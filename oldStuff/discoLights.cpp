#include "globals.h"
void updateCols(int* cols){
    int col =random(3);
    int domain =21;
    int step = random(domain);
    step = step  >domain/2 ? -1*step:step;
    cols[col] +=step;
    if (cols[col] <0) cols[col]=120;
    if (cols[col] >254) cols[col]=254;
}
void discoLights(CRGB* leds) {
    static int cols[3] ={120,120,120};
    int count =200 ;
    while (true) {
        int baseDel =200;
        int delShift =150;
        int del =baseDel +delShift*sin(count/1000.0*6.28);
        int colorChangeRate = (del)*3/delShift+1;
        count+=1;
        count = count % 1001;
        for (int i = 0; i < NUM_LEDS; i++) {
            if (i % (NUM_LEDS/4)==0) updateCols(cols);
            leds[i] =CRGB(cols[0], cols[1], cols[2]);
        }
        FastLED.show();

        delay(del);
    }





}