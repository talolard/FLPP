//
// Created by tal on 5/1/16.
//

#include "SqauresPattern.h"
#include "globals.h"

SqauresPattern::SqauresPattern(CRGB* l,int16_t nl) : PatternBase(l,nl){
    direction = random() %2 ==1 ? 1:-1;
}
void SqauresPattern::updateLeds() {
    static uint8_t  colorIt = 0;
    sinBrightNessInc();
    for (int i = 0; i < numLeds; i++) {
        leds[i] = ColorFromPalette(*currentPallete, map(i,0,numLeds,0,255)+colorIt*direction, brightness, LINEARBLEND);
    }
    colorIt+=5;

}