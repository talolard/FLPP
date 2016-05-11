//
// Created by tal on 5/5/16.
//

#include "PalleteServer.h"
#include "FastLED.h"

extern const TProgmemRGBPalette16 BlackWhite_p FL_PROGMEM =
        {
                CRGB::Black,
                CRGB::White,
                CRGB::White,
                CRGB::Black,

                CRGB::Black,
                CRGB::Grey,
                CRGB::Black,
                CRGB::White,

                CRGB::WhiteSmoke,
                CRGB::Black,
                CRGB::White,
                CRGB::Black,

                CRGB::Black,
                CRGB::White,
                CRGB::Black,
                CRGB::White
        };

extern const TProgmemRGBPalette16 northernLights_p FL_PROGMEM =
        {
                0X16163a, 0X2b3a63, 0X075663, 0X4be6ba,
                0X4be6ba, 0X2b3a63, 0X075663, 0X16163a,
                0X2b3a63, 0X4be6ba, 0X16163a, 0X075663,
                0X16163a, 0X4be6ba, 0X2b3a63, 0X4be6ba
        };
extern const TProgmemRGBPalette16 autumnLeaves_p FL_PROGMEM ={
0Xb70c0c,0Xc71221,0Xdc0606,0Xfa250c,
0Xfc9105,0Xfcb108,0X318d03,0X9dd523,
0Xfc9105,0Xfcb108,0X318d03,0X9dd523,
0Xb70c0c,0Xc71221,0Xdc0606,0Xfa250c
};
extern const TProgmemRGBPalette16 peakcock_p FL_PROGMEM = {
        0X010F28,0X0527F5,0X1DD1DA,0XF2A276,
        0XB0FB5E,0X2CBD07,0X0527F5,0X1DD1DA,
        0X1DD1DA,0XF2A276,0XB0FB5E,0X2CBD07,
        0X010F28,0X0527F5,0X1DD1DA,0XF2A276
};
extern const TProgmemRGBPalette16 desert_p FL_PROGMEM = {
0Xb56737,0Xe49a6b,0Xeb6810,0Xf48e46,
0Xeb6810,0Xb56737,0Xe49a6b,0Xf48e46,
0Xb56737,0Xe49a6b,0Xeb6810,0Xf48e46,
0Xeb6810,0Xb56737,0Xe49a6b,0Xb56737
};
PalleteServer::PalleteServer(){

}
PalleteServer* PalleteServer::getInstance(){
    if (!instance){
        instance = new PalleteServer();
    }
    return instance;
}
CRGBPalette16* PalleteServer::changePallete(uint8_t palleteCode) {
    switch (palleteCode){

        case 0:{ return new CRGBPalette16(CloudColors_p); break;}
        case 1:{ return new CRGBPalette16(LavaColors_p); break;}
        case 2:{ return new CRGBPalette16(OceanColors_p); break;}
        case 3:{ return new CRGBPalette16(ForestColors_p); break;}
        case 4:{ return new CRGBPalette16(RainbowColors_p); break;}
        case 5:{ return new CRGBPalette16(PartyColors_p); break;}
        case 6:{ return new CRGBPalette16(HeatColors_p); break;}
        case 7:{ return new CRGBPalette16(BlackWhite_p); break;}
        case 8:{ return new CRGBPalette16(northernLights_p); break;}
        case 9:{ return new CRGBPalette16(desert_p); break;}
        case 10:{ return new CRGBPalette16(peakcock_p); break;}
        case 11:{ return new CRGBPalette16(autumnLeaves_p); break;}

        default: {return new CRGBPalette16(PartyColors_p); break;}

    }

}