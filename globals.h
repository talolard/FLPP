//
// Created by tal on 4/30/16.
//

#ifndef MBLIGHTS_GLOBALS_H
#define MBLIGHTS_GLOBALS_H

#include "FastLED.h"
#ifdef TREE
#define NUM_STRIPS 24
#define LEDS_PER_STRIP 50
#define NUM_LEDS LEDS_PER_STRIP*NUM_STRIPS
#define FIRE_DELAY 45
#else
#define TREE
#define NUM_STRIPS 1
#define LEDS_PER_STRIP 150
#define NUM_LEDS LEDS_PER_STRIP*NUM_STRIPS
#define FIRE_DELAY 65
#endif
#endif //MBLIGHTS_GLOBALS_H
