//
// Created by tal on 5/5/16.
//

#ifndef MBLIGHTS_FlickerLightPattern_H
#define MBLIGHTS_FlickerLightPattern_H
#include "patternBase.h"
#include "stdint.h"
class FlickerLightPattern: public PatternBase {
    uint8_t lastColorIndex;
    void randomWalkColor();
public:
    FlickerLightPattern(CRGB* l= 0,int16_t nl=-1);
    void updateLeds();
};


#endif //MBLIGHTS_FlickerLightPattern_H
