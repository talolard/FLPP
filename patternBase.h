//
// Created by tal on 5/1/16.
//

#ifndef MBLIGHTS_PATTERNBASE_H
#define MBLIGHTS_PATTERNBASE_H

//#include <FastLED/lib8tion.h>
#include "stdint.h"
struct CRGB; //Forward declaration
class CRGBPalette16; //Forward declaration
class PalleteServer;
class PatternBase {
    protected:
        uint8_t brightness;
        CRGBPalette16* currentPallete;
        CRGB* leds;
    float brightNessBPM;
    uint8_t FPSIncrementer=0;

    uint16_t numLeds;
    uint8_t brightNessInc;
    void sinBrightNessInc();
    void FPSIncrementSin();
    void internalDelay();
public:
    uint8_t delayRate =0; //Zero means someone else should manage it.
    void updateFPS(uint8_t F) {FPS=F;delayRate=1000/FPS;}
    uint8_t FPS =25;
        bool hasPallete(){return currentPallete;}
        virtual CRGBPalette16* delPallete() { if (currentPallete) delete( currentPallete);}
        virtual void updateLeds() {};
        virtual void changePattern(CRGBPalette16* p){currentPallete =p;}
        virtual ~PatternBase(){ delPallete();}
    PatternBase(CRGB* l= 0,int16_t numLeds=-1);



};


#endif //MBLIGHTS_PATTERNBASE_H
