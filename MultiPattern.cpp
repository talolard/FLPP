//
// Created by tal on 5/6/16.
//

#include "globals.h"
#include "FlickerLightPattern.h";
#include "MultiPattern.h"
#include "PalleteServer.h"
#include "PatternServer.h"
MultiPattern::MultiPattern(CRGB* l,int16_t nl) :PatternBase(l,nl){
    //randomSeed(analogRead(0));
    PatternServer* PS =PatternServer::getInstance(leds);
    PalleteServer* PL =PalleteServer::getInstance();
    uint8_t pixelCount =0;
    numPieces =3;//random(2,5);
    patterns = new PatternBase*[numPieces];
    lastUpdate =new unsigned  long[numPieces];

    uint8_t chunksMade =0;
    while ( chunksMade <numPieces-1){
        uint8_t chunkSize = 4;//random(10,numLeds-pixelCount -1);
        lastUpdate[chunksMade] =0;
        patterns[chunksMade] = PS->changePattern(0,leds +max(pixelCount-3,0),chunkSize);
        //patterns[chunksMade]->changePattern(PL->changePallete(random(7)));
        //patterns[chunksMCade]->updateFPS(random(10,80));
        chunksMade++;
        pixelCount+=chunkSize;
    }
    lastUpdate[chunksMade] =0;
    patterns[chunksMade] = PS->changePattern(1,leds +pixelCount,numLeds-pixelCount);
    patterns[chunksMade]->changePattern(PL->changePallete(random(7)));

};
MultiPattern::~MultiPattern() {
    for (int i=0; i<numPieces; i++){
        delete (patterns[i]);
    }
    delete(lastUpdate);
    delete(patterns);
}

void MultiPattern::updateLeds() {
    unsigned long timestamp =millis();
    for (int i=0; i<numPieces; i++){
        if ((timestamp - lastUpdate[i]) > 1000 / patterns[i]->FPS)
        {
            patterns[i]->updateLeds();
            lastUpdate[i] =timestamp;

        }
    }

}