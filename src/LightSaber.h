#include <iostream>
using namespace std;
#pragma once

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
      
      void display()
      {  
         cout<<this->havePreON<< " "<<unsigned(this->red)<<" "<<unsigned(this->green)<<" "
         <<unsigned(this->blue)<<endl;
      }
};

#endif
