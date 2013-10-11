#pragma once
#include "ofMain.h"

class attractor{
public:
    attractor();
    
    void update();
    void setParams(float _x, float _y);
    
    ofVec2f pos;
    
    float cx, cy, orbitSize, orbitTime, circleSize;
};
