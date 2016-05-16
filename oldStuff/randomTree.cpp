//
// Created by tal on 4/30/16.
//
#include "globals.h"
#include "palletes.h"
CRGBPalette16 createRandomPallete(){
    CRGBPalette16 temp = CRGBPalette16();
    for (int i=0; i<16;i++){
        temp.entries[i] = CRGB(random8() ,random8() ,random8() );
    }
    return temp;

}
void randomTree(CRGB* leds){
    static bool first = true;
    static CRGBPalette16 pallet = friendlyPallete;
    static int brightness =30;
    if (first){
        pallet = createRandomPallete();
        first = false;
        for (int i=0;i<NUM_LEDS;i++){
            leds[i] = ColorFromPalette(pallet,i,30,LINEARBLEND);
        }
    }
    uint8_t ledsToUpdate = random8() %10+1 ;
    while (ledsToUpdate >0) {
        uint8_t nextLed = random8() % NUM_LEDS;
        leds[nextLed] = +1;
        ledsToUpdate--;
    }
    FastLED.show();
    delay(50);



}
