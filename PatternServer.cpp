//
// Created by tal on 5/6/16.
//

#include "PatternServer.h"
#include "SqauresPattern.h"
#include "FlickerLightPattern.h"
#include "Fire.h"
#include "CheckerPattern.h"
#include "Rule30Pattern.h"
PatternServer::PatternServer(CRGB *l) {
        leds =l;
}
PatternServer* PatternServer::getInstance(CRGB* leds) {
    if (!instance){
        instance = new PatternServer(leds);
    }
    return instance;
}
PatternBase* PatternServer::changePattern(uint8_t patternNum,CRGB* subLeds,uint32_t chunkSize) {
    if (!subLeds){
        subLeds =leds;
    }
    if (chunkSize==-1){
        chunkSize ==NUM_LEDS;
    }
    switch (patternNum){
        case 0:{  return new Fire(subLeds, chunkSize); break; }
        case 1:{  return new SqauresPattern(subLeds, chunkSize); break; }
        case 2:{  return new CheckerPattern(subLeds, chunkSize); break; }
        case 3:{  return new FlickerLightPattern(subLeds, chunkSize); break; }
        case 4:{  return new Rule31Pattern(subLeds, chunkSize); break; }
        default: {return new Fire(subLeds, chunkSize); break;}
    }
    return currentPattern;
}