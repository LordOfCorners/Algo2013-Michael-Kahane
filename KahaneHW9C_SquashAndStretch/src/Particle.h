//
//  Particle.h
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
  public:
    Particle();
    
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f force );
    void addDampingForce();
    void resetForces();
    void squash();
    void stretch();

    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    ofVec2f damping;  // could also be a ofVec2f
    
    float width,height;
    float stretchAmount;
    bool squashBool, stretchBool;
    bool shrink = true;
    bool unstretch = true;
    bool stretchB = true;
    float rotation = 0;
};