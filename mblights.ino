#include "globals.h"
/*#include "discoLights.cpp"
/*#include "randomTree.cpp"
#include "squares.cpp"
#include "patternBase.h"*/
#include "SqauresPattern.h"
#include "FlickerLightPattern.h"
#include "Fire.h"
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
#ifdef TREE
    FastLED.addLeds<WS2812, 29,BRG>(leds,20*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 30,BRG>(leds,1*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 31,BRG>(leds,1*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 32,BRG>(leds,2*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 33,BRG>(leds,3*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 34,BRG>(leds,4*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 35,BRG>(leds,5*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 36,BRG>(leds,6*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 37,BRG>(leds,7*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 38,BRG>(leds,8*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 39,BRG>(leds,9*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 40,BRG>(leds,10*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 41,BRG>(leds,11*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 42,BRG>(leds,12*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 43,BRG>(leds,13*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 44,BRG>(leds,14*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 45,BRG>(leds,15*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 46,BRG>(leds,16*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 47,BRG>(leds,17*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 48,BRG>(leds,18*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 49,BRG>(leds,19*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 50,BRG>(leds,20*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 51,BRG>(leds,20*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 52,BRG>(leds,20*50, LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 53,BRG>(leds,20*50, LEDS_PER_STRIP);
#endif

#ifdef BEAR
    FastLED.addLeds<WS2812, 8,BRG>(leds,LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 34,BRG>(leds,LEDS_PER_STRIP);
    FastLED.addLeds<WS2812, 35,BRG>(leds,LEDS_PER_STRIP);
#endif



    //FastLED.addLeds<WS2812, 8,GRB>(leds, NUM_LEDS);
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
    static uint8_t tree_part =0;
    random16_add_entropy( random());
    Changer->updateLeds();
     //   FastLED[tree_part++ %24].showLeds(255);
    FastLED.show();

}
// Created by tal on 4/9/16.

