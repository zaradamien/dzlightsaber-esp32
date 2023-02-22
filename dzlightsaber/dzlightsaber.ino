// #include "AudioSystem.h"
// #include "AudioOutput.h"
// #include "SynthSound.h"
// #include "sfx/sounds.h"


// AudioSystem audioSystem(22050, 500);
// AudioOutput audioOutput;
// SynthSound *humSound = 0;
#include "Arduino.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"
#include <FastLED.h>

// ---------------------------- SABER CONFIG -------------------------------
#include "saber_config.h"
#include "KyloRenSaber.h" 


// // ---------------------------- SETTINGS -------------------------------
// #define NUM_LEDS 60         // number of microcircuits WS2811 on LED strip (note: one WS2811 controls 3 LEDs!)
// #define BTN_HOLD_TIMEOUT 800     // button hold delay, ms
// #define BRIGHTNESS 255      // max LED brightness (0 - 255)
// #define LED_PIN 4


static const int buttonPin = 17;
int pressed = 0;
bool isSaberOn = false;
bool preOnDone = false;


// // ---------------------------- SD / AMP -------------------------------
// Digital I/O used
#define SD_CS          5
#define SPI_MOSI      23    // SD Card
#define SPI_MISO      19
#define SPI_SCK       18

#define I2S_DOUT  22
#define I2S_BCLK  26
#define I2S_LRC   25
 




// CRGB ledsStrip[NUM_LEDS];

// AudioSystem audioSystem(22050, 500);
// AudioOutput audioOutput;
// SynthSound *humSound = 0;

byte switchColor = 0;

LightSaber s1= LightSaber();
KyloRenSaber* k1;

const char* audiofilenames[] = {
  "/vader/vader_menu.wav",
  "/kyloren/kylo_menu.wav",
  "/kyloren/kylo_wait.wav"
  };

void setup() {

    Serial.begin(115200);
    Serial.print("OK");
    
    // SD
    pinMode(SD_CS, OUTPUT);      
    digitalWrite(SD_CS, HIGH);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

    // Blade off init
    FastLED.addLeds<WS2811, LED_PIN, GRB>(ledsStrip, NUM_LEDS);
    FastLED.setBrightness(100);  // ~40% of LED strip brightness
    for (int i = 0; i < NUM_LEDS; i++ ) {
      ledsStrip[i].r = 0;
      ledsStrip[i].g = 0;
      ledsStrip[i].b = 0;
    }
    FastLED.show();

    // Create kylo saber
    k1 = new KyloRenSaber();

    // SD + SOUND
    if(!SD.begin(SD_CS))
    {
      Serial.println("Error talking to SD card!");
      while(true);  // end program
    } else {
      Serial.println("Connected to SD card!");
    }


    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(18); // 0...21

    // audio.connecttoFS(SD,"/vader/vader_menu.wav");
    audio.connecttoSD("/kyloren/kylo_menu.wav");

}


void loop() {

    audio.loop();  
    
    // Calculate time for button
    static int time = 0;
    int t = millis();
    int dt = time - t;
    time = t;


    // audio.connecttoFS(SD, audiofilenames[0]); // Play Audio 1
    // audio.connecttoFS(SD,"/kyloren/kylo_wait.wav");
  


    // // Test Switch color
    // k1->switchColor(switchColor);
    // switchColor = switchColor == 5 ? 0 : switchColor+1;

    // // Display Blade sequence
    // if (k1->isOn){
    //   // Serial.println("Blade / ON");
    //   k1->Blade(0);
    // }
    
    // // Menu BTN
    // btnMenuTick();
    
    // Power On/Off BTN
    btnOnOffTick();


    // if(!digitalRead(buttonPin))
    // {    
    //   pressed += dt;

    //   // Serial.print("pressed");
    //   // Serial.print("\t\t");
    //   // Serial.print(pressed);
    //   // Serial.println();

    //   if(pressed < -2000)
    //   {
    //     if (isSaberOn){
    //       isSaberOn = false;
    //       Serial.print("OFF"); Serial.print("\t\t");
    //       // k1->turnOff();
    //       preOnDone = false;   

    //     } else {
    //       Serial.print("ON"); Serial.print("\t\t");
          
    //       // Turn On
    //       isSaberOn = true;
    //       k1->turnOn(preOnDone);  
    //       if (!preOnDone){
    //         preOnDone = true;      
    //       }
    //     }
    //     pressed = 0;   
    //   }
    // }
}



#define DEBUG 1   
#define BTN_HOLD_TIMEOUT 1000  
#define EXIT_MENU_TIMEOUT 5000  

boolean btnState, btn_flag, hold_flag;
unsigned long btn_timer;
byte btn_counter;   

void btnOnOffTick() {
  
  // Read Button  
  btnState = !digitalRead(buttonPin);

  // Button is pressed
  if (btnState && !btn_flag) {
    btn_flag = 1;
    btn_counter++;
    btn_timer = millis();
  }

  // Button released
  if (!btnState && btn_flag) {
    btn_flag = 0;
    hold_flag = 0;
  }

  // Button is held down during BTN_HOLD_TIMEOUT
  if (btn_flag && btnState && (millis() - btn_timer > BTN_HOLD_TIMEOUT) && !hold_flag) {


    if (!isSaberOn){
      Serial.println(F("Turn On"));            
      
      // Turn On
      isSaberOn = true;
      k1->turnOn(preOnDone);  
      if (!preOnDone){
        preOnDone = true;      
      }

    } else {
      Serial.println(F("Turn Off"));            
      isSaberOn = false;
      Serial.print("OFF"); Serial.print("\t\t");
      // k1->turnOff();
      preOnDone = false;  
    }

    hold_flag = 1;
    btn_counter = 0;
  }

  // Multiple time clicked
  if ((millis() - btn_timer > BTN_HOLD_TIMEOUT) && (btn_counter != 0)) {
  
    if (isSaberOn) {

      // Clicked 3 times -> Change color
      if (btn_counter >= 3) {               // 3 press count
        
        Serial.println(F("Switch Color"));

        // Change color
        switchColor++;

        // Go back to first color
        switchColor = switchColor > 5 ? 0 : switchColor;

        Serial.print("New Color ");

        // Switch color
        k1->switchColor(switchColor);
          
      }

    }

    // Reset counter
    btn_counter = 0;
  }
}



boolean btnMenuState, isBtnMenuPressed = false, isBtnMenuHold = false, isMenuOpened = false;
unsigned long btnMenutimer;
byte btnMenucounter;   
int menuOpt = 0, selectedMenuOpt = 0;

void btnMenuTick() {
  
  // Read Button  
  btnMenuState = !digitalRead(buttonPin);

  // Button is pressed
  if (btnMenuState && !isBtnMenuPressed) {
    isBtnMenuPressed = true;
    btnMenucounter++;
    btnMenutimer = millis();
  }

  // Button released
  if (!btnMenuState && isBtnMenuPressed) {
    isBtnMenuPressed = false;
    isBtnMenuHold = 0;
  }

  // Exit menu when no action during EXIT_MENU_TIMEOUT
  if (millis() - btnMenutimer > EXIT_MENU_TIMEOUT && isMenuOpened){
    Serial.println(F("EXIT MENU"));
    isMenuOpened = false;
    menuOpt = 0;
  }

  // Button is held down during BTN_HOLD_TIMEOUT
  if (isBtnMenuPressed && btnMenuState && (millis() - btnMenutimer > BTN_HOLD_TIMEOUT) && !isBtnMenuHold) {
    isBtnMenuHold = 1;
    btnMenucounter = 0;
     
    // Change Menu
    menuOpt++;  
    menu(menuOpt);
    isMenuOpened = true;
  }

  // Multiple time clicked
  if ((millis() - btnMenutimer > BTN_HOLD_TIMEOUT) && (btnMenucounter != 0)) {
  
    // if (isSaberOn) {
      
      // Clicked 2 times to validate the menu
      if (btnMenucounter == 2 && isMenuOpened) {            
        Serial.println(F("MENU VALIDATE"));
        selectedMenuOpt = menuOpt;
        isMenuOpened = false;
        Serial.println(F("EXIT MENU"));
      }

    // }

    // Reset counter
    btnMenucounter = 0;
  }

}



  void menu(int menuOpt) {

    menuOpt = menuOpt > 4 ? 0 : menuOpt;
    switch (menuOpt) {
      case 0:
        Serial.println("Menu 0");
        audio.connecttoFS(SD, audiofilenames[0]);
        break;
      case 1:
        Serial.println("Menu 1");
        audio.connecttoFS(SD, audiofilenames[1]);
        break;
        break;
    }
  }
