//
//  Sphere.cpp
//  vectors
//
//  Created by Michael Kahane on 9/3/13.
//
//

#include "Sphere.h"

Sphere::Sphere(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSeedRandom();
}

void Sphere::setup(ofColor _ballColor, ofVec3f _vel, ofVec3f _pos, float _r){
    ballColor = _ballColor;
    vel=_vel;
    pos=_pos;
    r=_r;
}

void Sphere::update(){
    pos += vel;

    if(pos.x<-200+r || pos.x > 200-r) vel.x *= -1;
    if(pos.y<-200+r || pos.y > 200-r) vel.y *= -1;
    if(pos.z<-200+r || pos.z > 200-r) vel.z *= -1;


    
    
    
}

void Sphere::draw(){
    ofSetColor(ballColor);
    ofDrawSphere(pos.x,pos.y,pos.z,r);
}