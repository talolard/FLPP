//
// Created by tal on 5/10/16.
//

#ifndef MBLIGHTS_Rule31Pattern_H
#define MBLIGHTS_Rule31Pattern_H

#include "patternBase.h"
class Rule31Pattern : public PatternBase{
    uint8_t* cellColors;
    bool ruleset[8] = {0,1,0,1,1,0,1,0};
    bool rules(bool a,bool b, bool c);
    bool* cells[2];

    uint8_t currentCell;

    void updateCells();
public:
    Rule31Pattern(CRGB* l= 0,int16_t nl=-1);
    ~Rule31Pattern();
    void updateLeds();
};

#endif //MBLIGHTS_Rule31Pattern_H
