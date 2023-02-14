#ifndef KyloRenSaber_h
#define KyloRenSaber_h
#include "LightSaber.h" 


 class KyloRenSaber : public LightSaber
 {
 private: 
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
    };

 };

#endif
