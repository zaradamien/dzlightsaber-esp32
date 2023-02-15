// // #include "AudioSystem.h"
// // #include "AudioOutput.h"
// // #include "SynthSound.h"
// // #include "sfx/sounds.h"


// // AudioSystem audioSystem(22050, 500);
// // AudioOutput audioOutput;
// // SynthSound *humSound = 0;
// #include "Arduino.h"
// #include "Audio.h"
// #include "LightSaber.h" 
// #include <SD.h>
// #include "FS.h"
// #include <FastLED.h>

// // ---------------------------- SABER CONFIG -------------------------------
// #include "saber_config.h"

// // ---------------------------- SETTINGS -------------------------------
// #define NUM_LEDS 60         // number of microcircuits WS2811 on LED strip (note: one WS2811 controls 3 LEDs!)
// #define BTN_TIMEOUT 800     // button hold delay, ms
// #define BRIGHTNESS 255      // max LED brightness (0 - 255)
// #define LED_PIN 4

// // microSD Card Reader connections
// #define SD_CS          5
// #define SPI_MOSI      23 
// #define SPI_MISO      18
// #define SPI_SCK       19
 
// // I2S Connections
// #define I2S_DOUT      22
// #define I2S_BCLK      26
// #define I2S_LRC       25
 
//  // Create Audio object
// Audio audio;

// // // Define the array of leds
// // CRGB leds[NUM_LEDS];


// static const int buttonPin = 17;

// int pressed = 0;
// bool on = false;

// byte nowColor, red, green, blue, redOffset, greenOffset, blueOffset;
// // CRGB leds[NUM_LEDS];

// // AudioSystem audioSystem(22050, 500);
// // AudioOutput audioOutput;
// // SynthSound *humSound = 0;

// void setup() {

//     Serial.begin(115200);
//     Serial.print("OK");


//   // sounds.play(audioSystem, 0, 0.5, 1);  
//   // humSound = new SynthSound();
//   // humSound->init(audioSystem);
//   // audioSystem.play(humSound);

//     // // Set microSD Card CS as OUTPUT and set HIGH
//     // pinMode(SD_CS, OUTPUT);      
//     // digitalWrite(SD_CS, HIGH); 

//     // // Initialize SPI bus for microSD Card
//     // SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);



//     // if(!SD.begin(SD_CS))
//     // {
//     //   Serial.println("Error accessing microSD card!");
//     //   while(true); 
//     // } else {
//     //   Serial.println("ACCESS OK");
//     // }
    
//     // // Setup I2S 
//     // audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    
//     // // Set Volume
//     // audio.setVolume(5);
    
//     // // Open music file
//     // audio.connecttoFS(SD,"/test.mp3");




//     FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
//     FastLED.setBrightness(100);  // ~40% of LED strip brightness
//     setAll(0, 0, 0);             // and turn it off

// }

// void loop() {

//   // Calculate time for button
//   static int time = 0;
//   int t = millis();
//   int dt = time - t;
//   time = t;


//     // Serial.print("OloopK");
//     // audio.loop();   

    
//   // preonSequence(100);
//   //kyloSequence(50);

// //         setPixel(1, 255, 0,0);
// //         setPixel(6, 20, 0,0);

// //     leds[4].r = 40;
// //     leds[4].g = 40;
// //     leds[4].b = 0;
// // FastLED.show();

//   if(!digitalRead(buttonPin))
//   {    
//     pressed += dt;

//     Serial.print("pressed");
//     Serial.print("\t\t");
//     Serial.print(pressed);
//     Serial.println();

//       if(pressed < -2000)
//       {
//         if (on){
//           on = false;
//           Serial.print("OFF"); Serial.print("\t\t");
//           turnOff();
//         } else {
//           on = true;
//           Serial.print("ON"); Serial.print("\t\t");
//           turnOn();
//         }
        
//         pressed = 0;  
        
//       }
//   }
// }



// void kyloSequence(int delayBetweenSequence){
//     Serial.print("preon");
//     for ( int i = 0; i < 24; ++i)
//     {
//         for ( int j = 0; j < 14; ++j)
// 	      {
//             // check if value exists
//             if (kyloBlade[i][j].to != 0){
//     	        lightFromTo(kyloBlade[i][j]);
//     	      }
// 	      }
  
// 	    // add delay between sequence
//       delay(delayBetweenSequence);
//     }
// }

// void preonSequence(int delayBetweenSequence){
//     Serial.print("preon");
//     for ( int i = 0; i < sequenceRows; ++i)
//     {
//         for ( int j = 0; j < sequenceColumns; ++j)
// 	      {
//             // check if value exists
//             if (kyloPreon[i][j].to != 0){
//     	        lightFromTo(kyloPreon[i][j]);
//     	      }
// 	      }
  
// 	    // add delay between sequence
//       delay(delayBetweenSequence);
//     }
// }


// void lightFromTo(ledLigth sequence) {
//   Serial.print("Light");
//     for (int i = sequence.from; i <= sequence.to; ++i)
//     {
//         // cout << "z :" << z << "\n\r";
//         // cout << "sequence color brightness :" << sequence.brightness << "\n\r";
//         // cout << "sequence color r :" << sequence.color.r << "\n\r";
//         // cout << "sequence color g :" << sequence.color.g << "\n\r";
//         // cout << "sequence color b :" << sequence.color.b << "\n\r";
        
//         int substractRGB = 0;
//         switch (sequence.brightness) {
//             case 100:
//               substractRGB = 0;
//               break;
//             case 75:
//               substractRGB = 64;
//               break;
//             case 50:
//               substractRGB = 128;
//               break;
//             case 25:
//               substractRGB = 192;
//               break;
//             case 0:
//               substractRGB = 255;
//               break;
//         }

//         int ledRed = sequence.color.r - substractRGB;
//         if (sequence.color.r - substractRGB < 0){
//           ledRed = 0;                    
//         }

//         int ledGreen = sequence.color.g - substractRGB;
//         if (sequence.color.g - substractRGB < 0){
//           ledGreen = 0;                    
//         } 

//         int ledBlue = sequence.color.b - substractRGB;
//         if (sequence.color.b - substractRGB < 0){
//           ledBlue = 0;                    
//         } 
        
//          Serial.print(ledRed);
//          Serial.print(" ");
//          Serial.print(ledGreen);
//          Serial.print(" ");
//          Serial.print(ledBlue);
//         Serial.print("\n\r");
//         setPixel(i, ledRed, ledGreen, ledBlue);
//         // setPixel(i, 255, 0, 0);
//         FastLED.show();
//         // delay(25);
//     }
// }


// void setPixel(int Pixel, byte red, byte green, byte blue) {
//   leds[Pixel].r = red;
//   leds[Pixel].g = green;
//   leds[Pixel].b = blue;
// }

// void setAll(byte red, byte green, byte blue) {
//   for (int i = 0; i < NUM_LEDS; i++ ) {
//     setPixel(i, red, green, blue);
//   }
//   FastLED.show();
// }

// void light_up(byte red, byte green, byte blue) {
//   for (char i = 0; i <= (NUM_LEDS - 1); i++) {        
//     setPixel(i, red, green, blue);
//     FastLED.show();
//     delay(25);
//   }
// }

// void light_down() {
//   for (char i = (NUM_LEDS - 1); i >= 0; i--) {      
//     setPixel(i, 0, 0, 0);
//     FastLED.show();
//     delay(25);
//   }
// }

// void turnOn()
// {
//     Serial.print("+++++++++ turnON +++++++++");
//     light_up(255,255,0);
     
// }

// void turnOff()
// {
//     Serial.print("+++++++++ turnOff +++++++++");
//     light_down();          
//     delay(500);
// }


// void setColor(byte color) {
//   switch (color) {
//     // 0 - red, 1 - green, 2 - blue, 3 - pink, 4 - yellow, 5 - ice blue
//     case 0:
//       red = 255;
//       green = 0;
//       blue = 0;
//       break;
//     case 1:
//       red = 0;
//       green = 0;
//       blue = 255;
//       break;
//     case 2:
//       red = 0;
//       green = 255;
//       blue = 0;
//       break;
//     case 3:
//       red = 255;
//       green = 0;
//       blue = 255;
//       break;
//     case 4:
//       red = 255;
//       green = 255;
//       blue = 0;
//       break;
//     case 5:
//       red = 0;
//       green = 255;
//       blue = 255;
//       break;
//   }
// }

// // void turnOn()
// // {
// //     Serial.print("turnON ++ ");
// //   // sounds.play(audioSystem, 0, 0.5, 1);  
// //   // humSound = new SynthSound();
// //   // humSound->init(audioSystem);
// //   // audioSystem.play(humSound);
// //   // on = true;
// //   // visibleLeds = 0;
// //   //gyro.wakeUp();
// // }


// // void turnOff()
// // {
// //   //   Serial.print("turnOff --");
// //   // sounds.play(audioSystem, 1, 0.5, 1);  
// //   // audioSystem.stop(humSound);
// //   // humSound = 0;   
// //   // on = false;
// //   //visibleLeds = ledCount * speed + 100;
// // }




// void __light_up(byte red, byte green, byte blue) {
//   for (char i = 0; i <= (NUM_LEDS / 2 - 1); i++) {        
//     setPixel(i, red, green, blue);
//     setPixel((NUM_LEDS - 1 - i), red, green, blue);
//     FastLED.show();
//     delay(25);
//   }
// }

// void __light_down() {
//   for (char i = (NUM_LEDS / 2 - 1); i >= 0; i--) {      
//     setPixel(i, 0, 0, 0);
//     setPixel((NUM_LEDS - 1 - i), 0, 0, 0);
//     FastLED.show();
//     delay(25);
//   }
// }