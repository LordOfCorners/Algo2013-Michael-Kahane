//
//  Particles.cpp
//  KahaneHW5B_NonCiruclarParticles
//
//  Created by Michael Kahane on 9/29/13.
//
//

#include "Particles.h"

Particle::Particle(){
    setParams(0,0,0,0);
    damping.set(0,0);
    image.loadImage("image3.png"); //does this count as a non-circle? If not, image.png is definitely not a circle
}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
    rotation = ofRandom(0,30);
}

void Particle::addForce(ofVec2f force){
    frc += force;
}

void Particle::resetForces(){
    frc.set(0,0);
}

void Particle::addDampingForce(){
    frc = frc - vel * damping;
}

void Particle::update(){
    vel+=frc;
    pos+=vel;
    
    //another thing I was playing with was uncommenting the below and then turning the auto background on.
    
//    if(rotation<360){
//    rotation+=rotation/100;
//    }
//    else{
//        rotation=0;
//        rotation+=rotation/1000;
//    }
    
}

void Particle::draw(){
    float sinOfTime = sin( ofGetElapsedTimef() * 2 );
    sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 1, 2);
    ofPushMatrix();
    ofRotate(rotation);
    image.draw(pos.x,pos.y,40*sinOfTimeMapped,45*sinOfTimeMapped);
    ofPopMatrix();

}