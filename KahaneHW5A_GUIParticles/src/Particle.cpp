//
//  Particle.cpp
//  NoiseParticles
//
//  Created by Charlie Whitney on 9/18/13 ////thanks! -Michael
//
//

#include "Particle.h"

void Particle::setup( ofVec2f rVel, ofPoint _pos){
    vel = rVel;
    age = 0;
    lifespan = ofRandom(50, 150);
    
    pos = _pos;
    bIsDead = false;
};

void Particle::update(){
    
    // Generate some noise based on where we are with x and y.  The particle slows down due to our multiplying the
    // velocity by 0.97, but we still want a lot of noise motion.  for this reason we pass in something we know will keep moving.  Time!
    // This is 3D noise.
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    
    // How close is our particle to dying.  0.0 = newborn, 1.0 = death
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    // use sin and cos to give us some sweepy circular motion.  The closer we are to death, the more noise we add.
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
    pos += vel;
    vel *= 0.97;
    
    
    age++;
    
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
};

void Particle::draw(float radius){
    if( bIsDead ){
        return;
    }
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    ofEllipse( pos, radius * agePct, (radius * agePct)-3  );         // The older pour particle is, the smaller it gets.
};

