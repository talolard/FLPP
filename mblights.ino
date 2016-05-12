#include "globals.h"
/*#include "discoLights.cpp"
/*#include "randomTree.cpp"
#include "squares.cpp"
#include "patternBase.h"*/
#include "SqauresPattern.h"
#include "FlickerLightPattern.h"
#include "Fire.h"
#include "palletes.h"
#include "PalleteServer.h"
#include "CheckerPattern.h"
#include "PatternServer.h"
#include "MultiPattern.h"
#include "PatternChanger.h"
PatternChanger* Changer;
#define DATA_PIN 10
PatternServer* PatternServer::instance =0;
PalleteServer* PalleteServer::instance=0;
PatternBase* P;
CRGB leds[NUM_LEDS];
void setup() {
    delay(200);
    randomSeed(analogRead(A0));

    FastLED.addLeds<WS2812, DATA_PIN,BRG>(leds, NUM_LEDS/3);
    FastLED.addLeds<WS2812, 8,GRB>(leds, NUM_LEDS);
    for (int i =0; i<NUM_LEDS; i++){
        leds[i] = CRGB::Red;
    }
    FastLED.show();
    delay(200);

    for (int i =0; i<NUM_LEDS; i++){
        leds[i] = CRGB::Purple;
    }
    FastLED.show();
    delay(200);
    //P->changePattern(PP->changePallete(3));
    Changer = new PatternChanger(leds);
    //P = new SqauresPattern(leds,NUM_LEDS-1);
    //P = Changer->
    for (int i =0; i<NUM_LEDS; i++){
        leds[i] = CRGB::Green;
    }
    Changer->changePattern();
    FastLED.show();
    delay(200);

}



void loop() {
    Changer->updateLeds();
    FastLED.show();
}
// Created by tal on 4/9/16.

