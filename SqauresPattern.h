//
// Created by tal on 5/1/16.
//
#ifndef MBLIGHTS_SQAURESPATTERN_H
#define MBLIGHTS_SQAURESPATTERN_H

#include "patternBase.h"
class SqauresPattern: public PatternBase {
    int8_t direction;
public:
    SqauresPattern(CRGB* l= 0,int16_t nl=-1);
void updateLeds();
};


#endif //MBLIGHTS_SQAURESPATTERN_H
