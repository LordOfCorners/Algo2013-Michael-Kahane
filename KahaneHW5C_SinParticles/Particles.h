//
//  Particles.h
//  KahaneHW5C_SinParticles
//
//  Created by Michael Kahane on 9/30/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    
    void update();
    void draw();
    void setParams(float _x, float _y);
    void addForce(ofVec2f force);
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos, vel, frc, damping;
    
    float cx, cy, orbitSize, orbitTime, circleSize;
    ofColor circleColor;
};
