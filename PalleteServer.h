//
// Created by tal on 5/5/16.
//

#ifndef MBLIGHTS_PALLETESERVER_H
#define MBLIGHTS_PALLETESERVER_H

#include "stdint.h"
class CRGBPalette16; //Forward Declaration
class PalleteServer {
protected:
public:
    static PalleteServer* instance;
    static PalleteServer* getInstance();
    PalleteServer();

    CRGBPalette16* changePallete(uint8_t palleteCode);

};


#endif //MBLIGHTS_PALLETESERVER_H
