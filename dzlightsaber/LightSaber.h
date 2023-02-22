#pragma once
#include <iostream>
#include <FastLED.h>
#include "Arduino.h"
#include "saber_config.h"

using namespace std;


#ifndef LightSaber_h
#define LightSaber_h

class LightSaber {


   public:
      String defaultColor;
      bool isOn;
      bool havePreON;
      uint8_t red, green, blue;
      Color saberColor;

      //Default Construct
      LightSaber()
      {
         this->defaultColor = "GREEN";
         this->havePreON = false;
         this->isOn = false;
         this->saberColor = {0,255,0};
      }      

      //Construct
      LightSaber(bool havePreON,uint8_t red,uint8_t green, uint8_t blue)
      {
         this->defaultColor = "GREEN";
         this->havePreON = havePreON;
         this->isOn = false;
         this->saberColor = {red,green,blue};
      }
      
      void turnOn(bool preOnDone)
      {    
          // // PreON Sequence
          // if (this->havePreON && !this->isOn && !preOnDone){
          //   preON();
          // }

          // Blade Sequence
          Blade(5);

            // is On
          this->isOn = true;
      }

      void Blade(int delayBetweenSequence = 25)
      {  
          Serial.println("\n\r\n\rBlade");

          

          // Show Blade sequence
          // displaySequence(0,delayBetweenSequence, 0);
          displayBladeSequence(0);
      }

      void displayBladeSequence(int delayBetweenSequence = 25, int useSequenceColor = 0){
 
          // Play sound Blade
          audio.setVolume(15); // 0...21
          audio.connecttoSD("/vader/vader_menu.wav");
          audio.loop();
          delay(10);
          
          Serial.println("-- Blade sequence");

  
          for ( int i = 0; i < sequenceRows; ++i)
          {
              for ( int j = 0; j < sequenceColumns; ++j)
              {
                  // check if value exists
                  if (sequence[i][j].to != 0){
                    lightLedsFromTo(this->bladeSequence[i][j], useSequenceColor);
                  }
              }
            // add delay between sequence
            delay(delayBetweenSequence);
          }

          Serial.println("++ Blade sequence");
      }


      
      void preON(int delayBetweenSequence = 25)
      {  
          // Serial.println("preON\n\r");

          // Play sound preon

          // Show Preon sequence
          // displaySequence(1,delayBetweenSequence, 1);
          displaypreONSequence(delayBetweenSequence, 1);
      }


    void displaypreONSequence(int delayBetweenSequence = 25, int useSequenceColor = 0){

        FastLED.setBrightness(180);  // ~70% of LED strip brightness
        // Serial.println("preon");
        for ( int i = 0; i < sequenceRows; ++i)
        {
            for ( int j = 0; j < sequenceColumns; ++j)
            {
                // check if value exists
                if (sequence[i][j].to != 0){
                  lightLedsFromTo(this->preONSequence[i][j], useSequenceColor);
                }
            }
          // add delay between sequence
          delay(delayBetweenSequence);
        }

        FastLED.setBrightness(100);  // ~40% of LED strip brightness
        FastLED.show();
    }



  // Display parts of sequence
  void lightLedsFromTo(ledLigth sequence, int useSequenceColor = 0, int delayBetweenLeds=0) {
    // Serial.println("lightLedsFromTo\n\r");
    for (int i = sequence.from; i <= sequence.to; ++i)
    {   
        int substractRGB = 0;
        switch (sequence.brightness) {
            case 100:
              substractRGB = 0;
              break;
            case 75:
              substractRGB = 64;
              break;
            case 50:
              substractRGB = 128;
              break;
            case 25:
              substractRGB = 192;
              break;
            case 10:
              substractRGB = 230;
              break;
            case 0:
              substractRGB = 255;
              break;
        }

        // Serial.print("useSequenceColor ");
        // Serial.print(useSequenceColor);
        // Serial.print("\r\n");

        // Calculate color (for brightness)
        // Check if we use the saber color or sequnce color
        int ledRed = useSequenceColor == 0 ? this->saberColor.r - substractRGB : sequence.color.r - substractRGB;
        ledRed = ledRed < 0 ? 0 : ledRed;

        int ledGreen = useSequenceColor == 0 ? this->saberColor.g - substractRGB : sequence.color.g - substractRGB;
        ledGreen = ledGreen < 0 ? 0 : ledGreen;

        int ledBlue = useSequenceColor == 0 ? this->saberColor.b - substractRGB : sequence.color.b - substractRGB;
        ledBlue = ledBlue < 0 ? 0 : ledBlue;
        
        //  Serial.println(ledRed);
        //  Serial.println(" ");
        //  Serial.println(ledGreen);
        //  Serial.println(" ");
        //  Serial.println(ledBlue);
        // Serial.println("\n\r");
        setPixel(i, ledRed, ledGreen, ledBlue);
        FastLED.show();

        delay(delayBetweenLeds);
    }

  }

  // Color specified led  
  void setPixel(int Pixel, byte red, byte green, byte blue) {
    ledsStrip[Pixel].r = red;
    ledsStrip[Pixel].g = green;
    ledsStrip[Pixel].b = blue;
  }

  // Turn off
  void turnOff() {
    for (char i = (NUM_LEDS - 1); i >= 0; i--) {      
      setPixel(i, 0, 0, 0);
      FastLED.show();
      delay(5);
    }
    // is On
    this->isOn = false;
  }


  
  void switchColor(byte color) {
    // 0 - red, 1 - green, 2 - blue, 3 - pink, 4 - yellow, 5 - ice blue
    switch (color) {
      case 0:
        this->saberColor = {255,0,0};
        Serial.println("Red");
        break;
      case 1:
        this->saberColor = {0,0,255};
        Serial.println("Green");
        break;
      case 2:
        this->saberColor = {0,255,0};
        Serial.println("Blue");
        break;
      case 3:
        this->saberColor = {255,0,255};
        Serial.println("Pink");
        break;
      case 4:
        this->saberColor = {255,255,0};
        Serial.println("Yellow");
        break;
      case 5:
        this->saberColor = {0,255,255};
        Serial.println("Ice Blue");
        break;
    }
  }

  protected:
   
   ledLigth sequence[sequenceRows][sequenceColumns];

   ledLigth preONSequence[sequenceRows][sequenceColumns] = { 
      {{0,_NUM_LEDS_,0,_BLACK_}}
    };

   ledLigth bladeSequence[sequenceRows][sequenceColumns] = { {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,50,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,50,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,50,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,50,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,50,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}},
    {{0,_NUM_LEDS_,75,_GREEN_}}
    };

};

#endif
