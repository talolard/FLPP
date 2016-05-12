//
// Created by tal on 5/7/16.
//

#ifndef MBLIGHTS_PATTERNCHANGER_H
#define MBLIGHTS_PATTERNCHANGER_H

class PatternBase;
class CRGB;
#include "stdint.h"
class PatternChanger {
    CRGB* leds;
    PatternBase* currentPattern;
    unsigned long lastTimeStampPat;
    unsigned long lastTimeStampPal;
    unsigned long  patternTimeThresh;
    unsigned long  palleteTimeThresh;

public:
    void updateLeds();
    void changePattern();
    void changePallete();
    bool shouldChangePallete();
    bool shouldChangePattern();
    PatternChanger(CRGB* l);
};


#endif //MBLIGHTS_PATTERNCHANGER_H