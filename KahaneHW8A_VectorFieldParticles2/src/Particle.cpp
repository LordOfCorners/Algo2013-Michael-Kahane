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
    
    if(pos.x<-300|| pos.x>ofGetWindowWidth()+300 || pos.y>ofGetWindowHeight()+300 ){
        pos = ofVec2f( ofRandom(0,ofGetWindowWidth()), ofRandom(ofGetWindowHeight()*-1,0) );
    }
    
    ofVec2f straightUp;
    straightUp.set(0,-1);
    float pAngle;
    pAngle = straightUp.angleRad(vel);
    pAngle = ofMap(pAngle, -PI, PI, 0, 255);
    color.setHsb(pAngle, 255, 255, 100);
}

void Particle::draw() {
    ofSetColor(color);
    ofCircle( pos, 1 );
}