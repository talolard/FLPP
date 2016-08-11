//
// Created by tal on 5/7/16.
//

#include "PatternChanger.h"
#include "globals.h"
#include "PatternServer.h"
#include "PalleteServer.h"
#include "patternBase.h"

#include "Rule30Pattern.h"
#include "Fire.h"

PatternChanger::PatternChanger(CRGB* l){
    patternCode =0;
    palleteCode=0;
    currentPattern =0;
    leds =l;
    currentPattern =0;
    patternTimeThresh = 600; //30 sec
    palleteTimeThresh= /*patternTimeThresh/10*/20;
    lastTimeStampPal =millis();
    lastTimeStampPat = millis();
    changePattern();
}

void PatternChanger::updateLeds(){

    if (shouldChangePallete()){

        changePallete();
    }
    if (shouldChangePattern()){
        changePattern();
    }
    currentPattern->updateLeds();
#ifdef BEAR
    blackOutNose();
#endif

    if (currentPattern->delayRate){
        //If this pattern defines a delayRate.
        delay(currentPattern->delayRate);
    }
    else{
        FastLED.delay(beatsin8(0.5,60,200));
    }

}
void PatternChanger::changePattern(){
    if (currentPattern) {
        delete currentPattern;
    }
    PatternServer* PS = PatternServer::getInstance(leds);
    PS->getInstance(leds);

    currentPattern = PS->changePattern(patternCode++ %4,leds,NUM_LEDS);
    //currentPattern = new Fire(leds,NUM_LEDS);
    //changePallete();
}
void PatternChanger::changePallete(){
    PalleteServer* PL = PalleteServer::getInstance();
    currentPattern->delPallete();
    //if (!currentPattern->hasPallete())
    {
        currentPattern->changePattern(PL->changePallete(patternCode++ %30));
    }
}
bool PatternChanger::shouldChangePallete(){
    if ((millis() -lastTimeStampPal)/1000 > palleteTimeThresh){
        lastTimeStampPal =millis();
        return true;
    }
    return false;
}
bool PatternChanger::shouldChangePattern(){
    if ((millis() -lastTimeStampPat)/1000 > patternTimeThresh){
        lastTimeStampPat=millis();
        return true;
    }
    return false;
}
void PatternChanger::blackOutNose() {
        uint8_t NoseStart=38;
        uint8_t NoseEnd =47;
        for (int i=NoseStart; i<= NoseEnd; i++){
            leds[i] = CRGB::Black;
        }

}