//
//  Particles.cpp
//  KahaneHW5C_SinParticles
//
//  Created by Michael Kahane on 9/30/13.
//
//

#include "attractor.h"

attractor::attractor(){
    setParams(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    circleSize=ofRandom(30,50);
    orbitSize=3*circleSize;
    orbitTime=ofRandom(900,2000);
}

void attractor::setParams(float _x, float _y){
    cx=_x;
    cy=_y;
}

void attractor::update(){
    float t = ofGetElapsedTimeMillis()/orbitTime;
    pos.x = int(cx+orbitSize*cos(t));
    pos.y = int(cy+orbitSize*sin(t));
    orbitSize+=.05;

}
