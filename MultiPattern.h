//
// Created by tal on 5/6/16.
//

#ifndef MBLIGHTS_MULTIPATTERN_H
#define MBLIGHTS_MULTIPATTERN_H

#include "patternBase.h"
#include "stdint.h"
class CRGB;
class CRGBPalette16;
class MultiPattern :public PatternBase {
    uint8_t numPieces;
    PatternBase** patterns;
    unsigned  long* lastUpdate;
public:
    MultiPattern(CRGB* l= 0,int16_t nl=-1);
    virtual ~MultiPattern();
    CRGBPalette16* delPallete() {}
    void updateLeds();
};


#endif //MBLIGHTS_MULTIPATTERN_H
