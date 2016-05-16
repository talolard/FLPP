//
// Created by tal on 4/30/16.
//

#ifndef MBLIGHTS_PALLETES_H
#define MBLIGHTS_PALLETES_H
CRGB purple = CHSV( HUE_PURPLE, 255, 255);
CRGB green  = CHSV( HUE_GREEN, 255, 255);
CRGB black  = CRGB::Black;
CRGB yellow  = CRGB::Yellow;
CRGB blue  = CRGB::Blue;
CRGB red= CRGB::Red;

CRGBPalette16 friendlyPallete =CRGBPalette16(
        CRGB::Yellow,  CRGB::YellowGreen,  CRGB::Green,  CRGB::Blue,
        CRGB::Purple, CRGB::Red, CRGB::Purple,  CRGB::RoyalBlue,
        CRGB::Magenta,  CRGB::Brown,  CRGB::DeepPink,  CRGB::Pink,
        CRGB::Teal, purple, CRGB::DarkCyan,  black );
CRGBPalette16 greenPallete =CRGBPalette16(CRGB::Green,CRGB::DarkGreen,CRGB::DarkOliveGreen,CRGB::GreenYellow,
                                             CRGB::DarkSeaGreen,CRGB::LimeGreen,CRGB::DarkGreen,CRGB::PaleGreen,
                                             CRGB::Green,CRGB::DarkGreen,CRGB::DarkOliveGreen,CRGB::GreenYellow,
                                             CRGB::DarkSeaGreen,CRGB::LimeGreen,CRGB::DarkGreen,CRGB::PaleGreen
        );

CRGBPalette16 lavaPallete =LavaColors_p;
CRGBPalette16 oceanPallete =OceanColors_p;


#endif //MBLIGHTS_PALLETES_H
