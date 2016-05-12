//
// Created by tal on 5/6/16.
//

#ifndef MBLIGHTS_PATTERNSERVER_H
#define MBLIGHTS_PATTERNSERVER_H

#include "stdint.h"
class PatternBase;
class CRGB;
namespace  Pattern {
    enum {
        Fire = 0, Squares=1, Flicker=2, Checker=3    };
}
class PatternServer {
private:
    PatternServer(PatternServer const&);              // Don't Implement
    void operator=(PatternServer const&); // Don't implement
    PatternBase* currentPattern;
    CRGB* leds;
public:
    static PatternServer* instance ;
    static  PatternServer* getInstance(CRGB* l);
    PatternBase* changePattern(uint8_t patternNum,CRGB* subLeds=0,uint32_t chunkSize=-1);
    PatternServer(CRGB *l);
};


#endif //MBLIGHTS_PATTERNSERVER_H
