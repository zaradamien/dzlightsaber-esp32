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
      string defaultColor;
      bool havePreON;
      uint8_t red, green, blue;

      //Default Construct
      LightSaber()
      {
         this->defaultColor = "GREEN";
         this->havePreON = false;
         this->red = 0;
         this->green = 255;
         this->blue = 0;
      }      

      //Construct
      LightSaber(bool havePreON,uint8_t red,uint8_t green, uint8_t blue)
      {
         this->defaultColor = "GREEN";
         this->havePreON = havePreON;
         this->red = red;
         this->green = green;
         this->blue = blue;
      }
      
      // void set_preON(ledLigth sequence[35][10]) {
      //   this->preONSequence = sequence;
      // }

      // // Getter
      // ledLigth get_preON() {
      //   return preONSequence;
      // }


      void display()
      {  
         cout<<this->havePreON<< " "<<unsigned(this->red)<<" "<<unsigned(this->green)<<" "
         <<unsigned(this->blue)<<endl;
      }
      
      void preon(int delayBetweenSequence)
      {  
         if (this->havePreON){
            // Play sound preon

            // Show Preon sequence
            // displaySequence(sequence, delayBetweenSequence);
         }
      }


    void displaySequence(ledLigth sequence[sequenceRows][sequenceColumns], int delayBetweenSequence){
        // Serial.print("preon");
        for ( int i = 0; i < sequenceRows; ++i)
        {
            for ( int j = 0; j < sequenceColumns; ++j)
            {
                // check if value exists
                if (sequence[i][j].to != 0){
                  lightFromTo(sequence[i][j]);
                }
            }
      
          // add delay between sequence
          delay(delayBetweenSequence);
        }
    }


     
  void lightFromTo(ledLigth sequence) {
    Serial.print("Light");
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
            case 0:
              substractRGB = 255;
              break;
        }

        int ledRed = sequence.color.r - substractRGB;
        if (sequence.color.r - substractRGB < 0){
          ledRed = 0;                    
        }

        int ledGreen = sequence.color.g - substractRGB;
        if (sequence.color.g - substractRGB < 0){
          ledGreen = 0;                    
        } 

        int ledBlue = sequence.color.b - substractRGB;
        if (sequence.color.b - substractRGB < 0){
          ledBlue = 0;                    
        } 
        
         Serial.print(ledRed);
         Serial.print(" ");
         Serial.print(ledGreen);
         Serial.print(" ");
         Serial.print(ledBlue);
        Serial.print("\n\r");
        setPixel(i, ledRed, ledGreen, ledBlue);
        // setPixel(i, 255, 0, 0);
        FastLED.show();
        // delay(25);
    }

  }

  void setPixel(int Pixel, byte red, byte green, byte blue) {
    ledsStrip[Pixel].r = red;
    ledsStrip[Pixel].g = green;
    ledsStrip[Pixel].b = blue;
  }


  protected:
    ledLigth preONSequence[35][10];

};

#endif
