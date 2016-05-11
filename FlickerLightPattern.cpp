//
// Created by tal on 5/5/16.
//

#include "FlickerLightPattern.h"
#include "FastLED.h"
FlickerLightPattern::FlickerLightPattern(CRGB* l,int16_t nl) : PatternBase(l,nl){
    lastColorIndex =random8(255);
    uint8_t colorBpm =random8(1,20);
}
void FlickerLightPattern::randomWalkColor(){
     int8_t stepSize =1;//- rnum;// %3;

    lastColorIndex +=stepSize;
     lastColorIndex = (lastColorIndex+255) %255;
 }

void FlickerLightPattern::updateLeds() {


    randomWalkColor();
    for (int i = 0; i < numLeds; i++) {
        //CRGB color = HeatColor(lastColorIndex);;
        CRGB color =ColorFromPalette(*currentPallete, lastColorIndex, beatsin8(4,20,255), LINEARBLEND);

        leds[i] = color;
    }
    //delay(beatsin8(0.3,80,350));

}