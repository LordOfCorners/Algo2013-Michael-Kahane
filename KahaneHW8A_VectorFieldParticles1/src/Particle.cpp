//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

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
    color = ofColor(ofMap(pos.x,0,ofGetWindowWidth(),0,255), ofMap(pos.y,0,ofGetWindowHeight(),0,255),200,100);
    
    if(pos.x<ofGetWindowWidth()/-2 || pos.x>750 || pos.y>ofGetWindowHeight() ){
        pos = ofVec2f( ofRandom(0,750), ofRandom(ofGetWindowHeight()*-1,0) );
    }
}

void Particle::draw() {
    ofCircle( pos, 1 );
}