//
// Created by tal on 5/5/16.
//

#ifndef MBLIGHTS_CHECKERPATTERN_H
#define MBLIGHTS_CHECKERPATTERN_H

#include "patternBase.h"
#include "FastLED.h"
class CheckerPattern : public PatternBase {
protected:
    uint8_t checlerSize;
    void initialize();
public:
    CheckerPattern(CRGB *l = 0,int16_t nl=-1);
    virtual void changePattern(CRGBPalette16* p);

    void updateLeds();
};

#endif //MBLIGHTS_CHECKERPATTERN_H
