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
extern const TProgmemRGBPalette16 sunset_p FL_PROGMEM = {
        0X1a0000, 0X0a0000, 0Xff4800, 0X003542,
        0Xdc0606, 0Xff0000, 0Xfa250c, 0Xff4800,
        0X1a0000, 0X0a0000, 0Xff4800, 0Xdc0606,
        0X1a0000, 0X0a0000, 0Xff0000, 0Xfa250c
};

extern const TProgmemRGBPalette16 stars2_p FL_PROGMEM = {
        0X020005, 0X07000a, 0X08000a, 0Xfee97c,
        0X020005, 0X07000a, 0X000000, 0X07000a,
        0X0800a, 0X8f00b3, 0X020005, 0Xfee97c,
        0X08000a, 0X00000, 0X000000, 0X07000a,
};
extern const TProgmemRGBPalette16 stars_p FL_PROGMEM = {
        0X000000, 0X000205, 0X00050b, 0X003973,
        0X000000, 0X000205, 0X00050b, 0Xfee97c,
        0X000000, 0X000205, 0X00050b, 0X40b1e9,
        0X000000, 0Xfee97c, 0X00050b, 0X40b1e9
};

extern const TProgmemRGBPalette16 birds2_p FL_PROGMEM = {
        0Xfee97c, 0Xffa600, 0Xff4800, 0X39b1c2,
        0X0800ff, 0Xffa600, 0Xff4800, 0X0800ff,
        0X39b1c2, 0Xff4800, 0Xfee97c, 0X39b1c2,
        0X0800ff, 0Xff4800, 0Xffa600, 0X39b1c2,

};
extern const TProgmemRGBPalette16 birds1_p FL_PROGMEM = {
        0Xbf8f00, 0X294584, 0Xfa250c, 0X552245,
        0Xc71221, 0Xff0066, 0X294584, 0Xff0066,
        0Xbf8f00, 0Xfa250c, 0Xc71221, 0X552245,
        0Xbf8f00, 0X294584, 0Xff0066, 0X294594
};

extern const TProgmemRGBPalette16 eggs_p FL_PROGMEM = {
        0X001600, 0X33ff00, 0X001600, 0X001600,
        0X001600, 0X5e4305,0X001600, 0X236b06,
        0X33ff00, 0X001600, 0X33ff00, 0Xeaff00,
        0X001600, 0X236b0f, 0X001600, 0X33ff00,

};
extern const TProgmemRGBPalette16  north_light FL_PROGMEM = {
        0X4dff4d, 0X4be6ba, 0X0509FF, 0X075663,
        0X4dff4d, 0X16163a, 0X4be6ba, 0X0509FF,
        0X075663, 0X4dff4d, 0X16163a, 0X4be6ba,
        0X0509FF, 0X075663, 0X4dff4d, 0X075663
};
extern const TProgmemRGBPalette16 peacock_max_p  FL_PROGMEM = {

        0X010F28, 0X0527F5, 0X1DD1DA, 0XF2A276,
        0XB0FB5E, 0X2CBD07, 0X0527F5, 0X1DD1DA,
        0X1DD1DA, 0XF2A276, 0XB0FB5E, 0X2CBD07,
        0X010F28, 0X0527F5, 0X1DD1DA, 0XF2A276
};
extern const TProgmemRGBPalette16 autumnleaves FL_PROGMEM = {

        0Xb70c0c, 0Xc71221, 0Xdc0606, 0Xfa250c,
        0Xfc9105, 0Xfcb108, 0X318d03, 0X9dd523,
        0Xfc9105, 0Xfcb108, 0X318d03, 0X9dd523,
        0Xb70c0c, 0Xc71221, 0Xdc0606, 0Xfa250c
};
extern const TProgmemRGBPalette16 desert  FL_PROGMEM = {
        0X000000, 0Xeb6810, 0Xeb8d10, 0Xd35d0e,
        0X8b3d09, 0XFFC233, 0X000000, 0Xeb6810,
        0Xeb8d10, 0Xd35d0e, 0X8b3d09, 0XFFC233,
        0X000000, 0Xeb6810, 0Xeb8d10, 0Xd35d0e,
};
extern const TProgmemRGBPalette16 plasma_ball FL_PROGMEM = {

0XD10000, 0X8b1a8e, 0X030207, 0X9ABAF1,
0X030207, 0X6c29ad, 0XD10000, 0Xb83bb1,
0X030207, 0X9ABAF1, 0XD10000, 0X8b1a8e,
0XD10000, 0Xb83bb1, 0X030207, 0X6c29ad
};
extern const TProgmemRGBPalette16  sky  FL_PROGMEM = {
        0XF9F9F7, 0Xeef5fb, 0X8ec8ee, 0X2476c0,
        0X0555ae, 0XF9F9F7, 0Xeef5fb, 0X8ec8ee,
        0X2476c0, 0X0555ae, 0XF9F9F7, 0Xeef5fb,
        0X8ec8ee, 0X2476c0, 0X0555ae, 0X8ec8ee,
};
extern const TProgmemRGBPalette16 laba FL_PROGMEM = {
        0X000000, 0XFF1900, 0XFF0000, 0XFF8800,
        0XFF0000, 0XFF1900, 0XFF0000, 0XFF4D00,
        0X000000, 0XFF0000, 0XFF0000, 0XFF1900,
        0XFF4D00, 0XFF2A00, 0X000000, 0XFF2A00,
};
extern const TProgmemRGBPalette16 forest FL_PROGMEM = {
        0X001600, 0X33FF00, 0X001600, 0X001600,
        0X5E4305, 0X001600, 0X236B0F, 0X33FF00,
        0X001600, 0X33FF00, 0XEAFF00, 0X001600,
        0X236B0F, 0X001600, 0X33FF00, 0X5E4305,
};
extern const TProgmemRGBPalette16  bird FL_PROGMEM = {
        0XBF8F00, 0X294584, 0Xfa250c, 0X552245,
        0Xc71221, 0XFF0066, 0X294584, 0XFF0066,
        0XBF8F00, 0Xfa250c, 0Xc71221, 0X552245,
        0XBF8F00, 0X294584, 0XFF0066, 0X294584,
};
extern const TProgmemRGBPalette16  bird2 FL_PROGMEM = {
        0Xfee97c, 0XFFA600, 0XFF4800, 0X39B1C2,
        0X0800FF, 0XFFA600, 0XFF4800, 0X0800FF,
        0X39B1C2, 0XFF4800, 0Xfee97c, 0X39B1C2,
        0X0800FF, 0XFF4800, 0XFFA600, 0X39B1C2,
};
extern const TProgmemRGBPalette16  stars FL_PROGMEM = {
        0X000000, 0X000205, 0X00050b, 0X003973,
        0X000000, 0X000205, 0X00050b, 0Xfee97c,
        0X000000, 0X000205, 0X00050b, 0X40b1e9,
        0X000000, 0Xfee97c, 0X00050b, 0X40b1e9,
};
extern const TProgmemRGBPalette16  stars2 FL_PROGMEM = {
        0X020005, 0X07000a, 0X08000a, 0Xfee97c,
        0X020005, 0X07000a, 0X000000, 0X8f00b3,
        0X000000, 0X07000a, 0X08000a, 0X8f00b3,
        0X020005, 0Xfee97c, 0X08000a, 0X000000,
};
extern const TProgmemRGBPalette16 sunset FL_PROGMEM = {
        0X1a0000, 0X0a0000, 0XFF4800, 0X003542,
        0Xdc0606, 0XFF0000, 0Xfa250c, 0XFF4800,
        0X1a0000, 0X0a0000, 0XFF4800, 0Xdc0606,
        0X1a0000, 0X0a0000, 0XFF0000, 0Xfa250c,
};
extern const TProgmemRGBPalette16 laba_p FL_PROGMEM = {

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
        case 12:{ return new CRGBPalette16(sunset_p); break;}
        case 13:{ return new CRGBPalette16(stars2_p); break;}
        case 14:{ return new CRGBPalette16(stars_p); break;}
        case 15:{ return new CRGBPalette16(birds2_p); break;}
        case 16:{ return new CRGBPalette16(birds1_p); break;}


        case 17:{ return new CRGBPalette16(north_light); break;}
        case 18:{ return new CRGBPalette16(peacock_max_p); break;}
        case 19:{ return new CRGBPalette16(autumnleaves); break;}
        case 20:{ return new CRGBPalette16(desert); break;}
        case 21:{ return new CRGBPalette16(plasma_ball); break;}
        case 22:{ return new CRGBPalette16(sky); break;}
        case 23:{ return new CRGBPalette16(laba); break;}
        case 24:{ return new CRGBPalette16(forest); break;}
        case 25:{ return new CRGBPalette16(bird); break;}
        case 26:{ return new CRGBPalette16(bird2); break;}
        case 27:{ return new CRGBPalette16(stars); break;}
        case 28:{ return new CRGBPalette16(stars2); break;}
        case 29:{ return new CRGBPalette16(sunset); break;}
        case 30:{ return new CRGBPalette16(laba_p); break;}



        default: {return new CRGBPalette16(PartyColors_p); break;}

    }

}