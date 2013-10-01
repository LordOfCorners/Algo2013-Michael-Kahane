//
//  Particle.h
//  NoiseParticles
//
//  Created by Charlie Whitney on 9/18/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(){};
    void setup( ofVec2f rVel, ofPoint _pos );
    void update();
    void draw(float radius);
    
    ofVec2f pos;
    ofVec2f vel;
    int age, lifespan;
    bool bIsDead;
};
