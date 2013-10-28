//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( 0.01f );
    height = 20;
    width = 20;
}

void Particle::setParams( float px, float py, float vx, float vy ){
    pos.set( px, py );
    vel.set( vx, vy );
}

void Particle::addForce( ofVec2f force ){
    frc += force;
}

void Particle::addDampingForce() {
    frc = frc - vel * damping;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::update() {
    squash();
    
    if(stretchB) stretchAmount = ofClamp(abs(vel.x)+abs(vel.y),0,5);

    if(pos.x < (width/2) || pos.x > ofGetWindowWidth()-(width/2) ){
        vel.x*=-1;
        squashBool=true;
    }
    if(pos.y < (height/2) || pos.y > ofGetWindowHeight()-(height/2) ){
        vel.y*=-1;
        squashBool=true;
    }
    
    if(pos.x < 50 || pos.x > ofGetWindowWidth()-50 || pos.y < 50 || pos.y > ofGetWindowHeight()-50 ){
        stretchB = false;
            if(unstretch && stretchAmount > 1){
                stretchAmount  =0 ;
            }else if(!unstretch && stretchAmount < 3){
                stretchAmount =0;
            }
            if(stretchAmount<1) unstretch = false;
    }else{
        stretchB = true;
        unstretch = true;
    }
    cout << unstretch <<endl;
    vel = vel + frc;
    pos = pos + vel;
}

void Particle::draw() {
    ofPushMatrix();
    ofTranslate(pos.x,pos.y);
    ofRotate(rotation);
    ofSetColor(0);
    ofEllipse(0, 0, width, height + stretchAmount);
    ofSetColor(100,255,0);
//    ofLine(0,0,0,-10);
    ofPopMatrix();
}

void Particle::squash() {
    if(squashBool){
        if(width<12) shrink = false;
        if(shrink){
            width-=1;
        }else if(!shrink){
            width+=1;
        }
        if(!shrink && width>19) {
            squashBool=false;
            shrink=true;
        }
    }
}

void Particle::stretch() {

}

