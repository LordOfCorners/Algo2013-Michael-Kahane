//
//  Particles.cpp
//  KahaneHW5C_SinParticles
//
//  Created by Michael Kahane on 9/30/13.
//
//

#include "Particles.h"

Particle::Particle(){
    setParams(0,0);
    damping.set(0,0);
    circleSize=ofRandom(1,20);
    circleColor=ofColor(0,ofRandom(30,200),ofRandom(0,100),ofRandom(255*.20,255*.8));
    orbitSize=circleSize*30;
    orbitTime=ofRandom(900,2000);
}

void Particle::setParams(float _x, float _y){
    cx=_x;
    cy=_y;
}

void Particle::addForce(ofVec2f force){
//    frc += force;
}

void Particle::resetForces(){
//    frc.set(0,0);
}

void Particle::addDampingForce(){
//    frc = frc - vel * damping;
}

void Particle::update(){
    float t = ofGetElapsedTimeMillis()/orbitTime;
    pos.x = int(cx+orbitSize*cos(t));
    pos.y = int(cy+orbitSize*sin(t));
    
}

void Particle::draw(){
    float t = ofGetElapsedTimeMillis()/orbitTime;
    ofPushMatrix();
    ofSetColor(circleColor);
    ofRotate(ofRadToDeg(cos(t))); //COMMENT OUT THIS LINE TO MAKE IT CIRCULAR 
    ofEllipse(pos.x, pos.y, circleSize,circleSize/2);
    ofPopMatrix();
}