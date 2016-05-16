//
// Created by tal on 4/30/16.
//
#include "globals.h"
#define colorSize 24
CRGB colors[colorSize] = {CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,
                          CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,
                          CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,
                          CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue
};
CRGBPalette16 bluePallete =CRGBPalette16(CRGB::Blue,CRGB::Blue,CRGB::Blue,CRGB::Blue,
                                         CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,CRGB::CadetBlue,
                                         CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,CRGB::DarkBlue,
                                         CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue,CRGB::DeepSkyBlue
);
void initLedsSquares (CRGB* leds){


}
void squares (CRGB* leds){
    //FastLED.setBrightness(60);
    uint8_t ledStackSize = NUM_LEDS /3;
    uint8_t static colorIt =0;
    for (int i=0; i<NUM_LEDS; i++){
        leds[i] =ColorFromPalette(bluePallete,colorIt,55,LINEARBLEND);
        //colorIt = (colorIt +1)++;
        colorIt+=6;
    }
    //colorIt =(colorIt +1 )% colorSize;
    FastLED.show();
    delay(3);

}
