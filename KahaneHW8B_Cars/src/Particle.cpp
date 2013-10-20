//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
//    setParams(0,0,0);
    damping = ofVec2f( 0.01f );
}

void Particle::setParams( ofVec2f _pos, ofVec2f _vel ){
    pos.set( _pos );
    vel.set( _vel );
    
    lastPos.set( pos );
}

void Particle::addForce( ofVec2f force ){
    acc += force;       // F = MA
}

void Particle::seek( ofVec2f dest ) {
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofVec2f desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }

    ofVec2f steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}

void Particle::avoidCrash( Particle car ){
    if(pos.distance(car.pos) < 100){
        ofVec2f swerve;
        swerve.x = car.vel.x*-1;
        swerve.normalize();
        addForce( swerve );
    }
}


void Particle::update() {
    vel = vel + acc;
    pos = pos + vel;
    
    vel *= 0.97;
    
    acc *= 0;
    
    lastPos.set( pos );
}

void Particle::draw() {
//    ofCircle(pos.x, pos.y, 4);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt) + 90 );
        ofRect( 0,0, 20, 20);
    
    ofPopMatrix();
}