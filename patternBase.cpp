//
// Created by tal on 5/1/16.
//

#include "globals.h"
#include "patternBase.h"
#include "PalleteServer.h"
PatternBase::PatternBase(CRGB *l,int16_t nl) {
    PalleteServer* PS = PalleteServer::getInstance();
    currentPallete =PS->changePallete(random8(30));
    leds=l;
    brightness =100;
    FastLED.setBrightness(brightness);
    if (nl==-1){
        nl = NUM_LEDS; //If it was unitialized set to maximum. This allows multiple parts with seperate patterns
    }
    numLeds =nl;
    brightNessBPM = 1.0 /(random() %10+1);
}

void PatternBase::internalDelay(){
    delay(delayRate);
}

void PatternBase::FPSIncrementSin() {
    int val =map(sin8_C(FPSIncrementer++),0,255,13,20);
    updateFPS(val);}
void PatternBase::sinBrightNessInc() {brightness =beatsin8(brightNessBPM,80,255);}