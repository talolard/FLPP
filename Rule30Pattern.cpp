//
// Created by tal on 5/10/16.
//

#include "Rule30Pattern.h"
#include "globals.h"

Rule31Pattern::Rule31Pattern(CRGB *l, int16_t nl) :PatternBase(l,nl) {
    cells[0] =new bool[numLeds];
    cells[1] =new bool[numLeds];
//    cellColors = new uint8_t[numLeds];
    for (int i =0; i<numLeds; i++){
    //    cellColors[i] =100;
       cells[currentCell][i] = random(2);
    }
    currentCell=0;
}
Rule31Pattern::~Rule31Pattern() {
    delete cells[0];
    delete cells[1];
    delete cellColors;
}
bool Rule31Pattern::rules (bool a, bool b, bool c) {
    if (a == 1 && b == 1 && c == 1) return ruleset[0];
    else if (a == 1 && b == 1 && c == 0) return ruleset[1];
    else if (a == 1 && b == 0 && c == 1) return ruleset[2];
    else if (a == 1 && b == 0 && c == 0) return ruleset[3];
    else if (a == 0 && b == 1 && c == 1) return ruleset[4];
    else if (a == 0 && b == 1 && c == 0) return ruleset[5];
    else if (a == 0 && b == 0 && c == 1) return ruleset[6];
    else if (a == 0 && b == 0 && c == 0) return ruleset[7];
}
void Rule31Pattern::updateCells() {
    uint8_t nextCell = (currentCell+1) %2;
    for (uint8_t i =0; i<numLeds;i++){
        cells[nextCell][i] =rules(cells[currentCell][i-1],cells[currentCell][i],cells[currentCell][(i+1)%numLeds]);
        cellColors[i] += cells[nextCell][i] ? random(5) :-1*random(5);
    }
    currentCell =nextCell;
}

void Rule31Pattern::updateLeds() {
    uint8_t temp = beatsin8(1,10,20);
    CRGB color = ColorFromPalette(*currentPallete, 10, 255, LINEARBLEND);
    for (uint8_t i =0; i<numLeds;i++){
        //if (random8()%temp ==0)
        {
            color = ColorFromPalette(*currentPallete, random8(255)/*cellColors[i]*/, 255, LINEARBLEND);
            leds[i]=color;//ColorFromPalette(*currentPallete, cellColors[i], 255, LINEARBLEND);
        }

    }
    CRGB last =leds[numLeds-1];

    for (int i = 1; i  <numLeds-1; i++) {
        //leds[i] =  (leds[i - 1] +leds[i] +leds[i+1])/3;
    }
    leds[0] = last;

    //updateCells();
}