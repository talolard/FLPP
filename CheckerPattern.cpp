//
// Created by tal on 5/5/16.
//

#include "CheckerPattern.h"
CheckerPattern::CheckerPattern(CRGB* l,int16_t nl) : PatternBase(l,nl){
    checlerSize=3;
    initialize();
}

void CheckerPattern::initialize() {
    CRGB color[5];
    for (int i=0; i<5; i++){
        //color[i]=CRGB(random() %255,random() %255,random() %255);
        color[i] = ColorFromPalette(*currentPallete, 16*i, brightness, LINEARBLEND); //TODO Change 16i to something better
    }
    uint8_t colorCounter =0;
    for (int i = 0; i < numLeds; i++) {
        if (i % checlerSize ==0) {
            colorCounter = (colorCounter +1) %5;
        }
        leds[i] =color[colorCounter];
    }
    //updateLeds();


}
void CheckerPattern::changePattern(CRGBPalette16* p){
    PatternBase::changePattern(p);
    initialize();
}
void CheckerPattern::updateLeds() {
        CRGB last = leds[numLeds - 1];

        for (int i = numLeds - 1; i > 0; i--) {
            leds[i] = leds[i - 1];
        }
        leds[0] = last;
/*    else{
        CRGB first =leds[0];
        for (int i=0; i<numLeds-1; i++){
            leds[i] =leds[i+1];
        }
        leds[numLeds-1] =first;
    }
    */
    sinBrightNessInc();
    //FastLED.setBrightness(brightness);
    //FPSIncrementSin();
}