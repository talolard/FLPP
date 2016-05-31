//
// Created by tal on 5/5/16.
//

#include "Fire.h"

Fire::Fire(CRGB* l,int16_t nl) : PatternBase(l,nl){
    delayRate=FIRE_DELAY;
    heat = new uint8_t[numLeds];
}
Fire::~Fire(){
    delete(heat);
}
void Fire::updateLeds()
{
    static uint8_t cool =0;
    cool++;
// Array of temperature readings at each simulation cell

    // Step 1.  Cool down every cell a little
    for( int i = 0; i < numLeds; i++) {
            heat[i] = qsub8( heat[i],  /*((beatsin8(0.1,3,100)) ) + 2*/random8(5));
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= numLeds - 3; k > 0; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    for (int strip =0; strip < NUM_STRIPS; strip++) {
        if (random8() < beatsin8(0.2, 10, 40)) {
            int y = random8(LEDS_PER_STRIP);
            heat[LEDS_PER_STRIP*strip+y] = qadd8(heat[y], random8(160, 255));
        }
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < numLeds; j++) {
        leds[j] = HeatColor( heat[j]);
    }
    static  uint8_t i =0;
    i++;

}
