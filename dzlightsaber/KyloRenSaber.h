#pragma once

#ifndef KyloRenSaber_h
#define KyloRenSaber_h
#include "LightSaber.h" 


 class KyloRenSaber : public LightSaber
 {
   
 private: 

  ledLigth preONSequence[sequenceRows][sequenceColumns] = { 
    {{0,5,50,_WHITE_},{6,7,25,_WHITE_},{9,9,25,_WHITE_},{11,11,25,_WHITE_},{15,17,100,_WHITE_},{18,21,25,_WHITE_},{23,24,25,_WHITE_}},
    {{0,10,50,_WHITE_},{13,15,100,_WHITE_},{19,20,50,_WHITE_},{23,26,50,_WHITE_}},
    {{0,1,25,_WHITE_},{6,9,100,_WHITE_},{12,14,25,_WHITE_}},
    {{0,14,100,_WHITE_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,9,50,_WHITE_},{12,15,25,_WHITE_},{22,24,50,_WHITE_},{29,29,50,_WHITE_},{32,34,50,_WHITE_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,4,50,_WHITE_},{7,17,50,_WHITE_},{22,32,50,_WHITE_},{33,41,25,_WHITE_},{42,48,50,_WHITE_}},
    {{0,4,25,_WHITE_},{4,9,50,_WHITE_},{10,13,25,_WHITE_}},
    {{0,2,50,_WHITE_},{3,5,25,_WHITE_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,2,50,_WHITE_},{3,5,25,_WHITE_},{9,11,50,_WHITE_},{13,14,25,_WHITE_}},
    {{0,1,50,_WHITE_},{2,4,25,_WHITE_},{8,11,25,_WHITE_}}, //4:18
    {{0,20,50,_WHITE_},{21,23,25,_WHITE_}}, 
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,11,50,_WHITE_},{17,17,50,_WHITE_},{19,20,25,_WHITE_}}, 
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,2,50,_WHITE_}}, //5:06
    {{0,3,50,_WHITE_},{4,8,25,_WHITE_},{9,11,50,_WHITE_},{11,14,25,_WHITE_},{15,17,50,_WHITE_},{17,20,25,_WHITE_}}, 
    {{0,_NUM_LEDS_,0,_BLACK_}},
    {{0,_NUM_LEDS_,0,_BLACK_}}
    //{{0,1,50,_WHITE_}} //6.06
  };

 public:
    // Parent Construct
    KyloRenSaber(bool havePreON,uint8_t red,uint8_t green, uint8_t blue) : LightSaber( havePreON,red,green,blue){}

    // Construct
    KyloRenSaber(){
      Setup();
    }
    
    
    void Setup(){
      this->defaultColor = "RED";
      this->havePreON = true;
      this->red = 255;
      this->green = 0;
      this->blue = 0;

      // LightSaber::set_preON(kylo_preon);
    };

      

    void displayTest(){
        
        for ( int i = 0; i < sequenceRows; ++i)
        {
            for ( int j = 0; j < sequenceColumns; ++j)
            {
                // check if value exists
                if (this->preONSequence[i][j].to != 0){
                  lightFromToTest(this->preONSequence[i][j]);
                }
            }
      
        }
    }


  void lightFromToTest(ledLigth sequence) {
    Serial.print("Light");
    for (int i = sequence.from; i <= sequence.to; ++i)
    {   
         Serial.print(sequence.color.r);
         Serial.print(" ");
         Serial.print(sequence.color.g);
         Serial.print(" ");
         Serial.print(sequence.color.b);
        Serial.print("\n\r");
        // setPixel(i, 255, 0, 0);
        FastLED.show();
        // delay(25);
    }

  }

 };

#endif
