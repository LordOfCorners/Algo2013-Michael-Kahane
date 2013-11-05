//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
// Color code from Jennifer Presto (https://github.com/jenniferpresto)

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
        
    ofVec2f straightUp;
    straightUp.set(0,-1);
    float pAngle;
    pAngle = straightUp.angleRad(vel);
    pAngle = ofMap(pAngle, -PI, PI, 0, 255);
    color.setHsb(pAngle, 255, 255, 150);
}

void Particle::draw(ofFbo _fbo) {
//    ofSetColor(color);
//    ofCircle( pos, 2 );
    
    _fbo.draw(pos.x,pos.y);
}

void Particle::reset(){
    pos = ofVec2f( ofRandom(-300,ofGetWindowWidth()+300), ofRandom(-300,ofGetWindowHeight()+300) );
    vel = ofVec2f(0,0);
}
