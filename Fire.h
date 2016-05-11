//
// Created by tal on 5/5/16.
//

#ifndef MBLIGHTS_FIRE_H
#define MBLIGHTS_FIRE_H

#include "patternBase.h"
#include "stdint.h"
#include "globals.h"
class Fire: public PatternBase {
    uint8_t*heat;
public:
Fire(CRGB* l= 0,int16_t nl=-1);
void updateLeds();
~Fire();
};


#endif //MBLIGHTS_FIRE_H
