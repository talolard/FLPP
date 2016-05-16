#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RGB Calibration code
//
// Use this sketch to determine what the RGB ordering for your chipset should be.  Steps for setting up to use:

// * Uncomment the line in setup that corresponds to the LED chipset that you are using.  (Note that they
//   all explicitly specify the RGB order as RGB)
// * Define DATA_PIN to the pin that data is connected to.
// * (Optional) if using software SPI for chipsets that are SPI based, define CLOCK_PIN to the clock pin
// * Compile/upload/run the sketch

// You should see six leds on.  If the RGB ordering is correct, you should see 1 red led, 2 green
// leds, and 3 blue leds.  If you see different colors, the count of each color tells you what the
// position for that color in the rgb orering should be.  So, for example, if you see 1 Blue, and 2
// Red, and 3 Green leds then the rgb ordering should be BRG (Blue, Red, Green).

// You can then test this ordering by setting the RGB ordering in the addLeds line below to the new ordering
// and it should come out correctly, 1 red, 2 green, and 3 blue.
//
//////////////////////////////////////////////////

#define NUM_LEDS 39

// Data pin that led data will be written out over
#define DATA_PIN 8
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);

    // Uncomment one of the following lines for your leds arrangement.
    FastLED.addLeds<WS2812B, DATA_PIN, BRG>(leds, NUM_LEDS);
}
void moveStripLeft(CRGB* leds){
    CRGB temp = leds[NUM_LEDS-1];
    for (int i= NUM_LEDS-1; i>0;i--){
        leds[i] =leds[i-1];
    }
    leds[0]=temp;
}
long unsigned int sinDelay(){
    static  int count =0;
    int baseDel =200;
    int delShift =150;
    int del =baseDel +delShift*sin(count/1000.0*6.28);
    count++;
    return del;


}
void loop() {
    for (int i=0; i<NUM_LEDS/3;i++){
        leds[i] = CRGB(255-i,i,i*i);
    }
    for (int i=NUM_LEDS/3; i<2*NUM_LEDS/3;i++){
        leds[i] = CRGB(i,100+i,100+i);
    }
    for (int i=2*NUM_LEDS/3; i<NUM_LEDS;i++){
        leds[i] = CRGB(120,50,255);
    }
    FastLED.show();
    delay(1000);
    leds[6] = CRGB(255,0,0);
    leds[7] = CRGB(255,0,0);
    leds[8] = CRGB(255,0,0);
    FastLED.show();
    delay(100);
    for (int i=0; i<NUM_LEDS*100; i++){
        moveStripLeft(leds);
        FastLED.show();
        delay(sinDelay());
    }
}//
// Created by tal on 4/9/16.
//

