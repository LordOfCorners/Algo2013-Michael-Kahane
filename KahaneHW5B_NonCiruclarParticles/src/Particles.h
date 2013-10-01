//
//  Particles.h
//  KahaneHW5B_NonCiruclarParticles
//
//  Created by Michael Kahane on 9/29/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    
    void update();
    void draw();
    void setParams(float px, float py, float vx, float vy);
    void addForce(ofVec2f force);
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos, vel, frc, damping;
    
    ofImage image;
    float sinOfTimeMapped;
    float rotation;
};
