//
//  Ball.cpp
//  vectors
//
//  Created by Michael Kahane on 9/3/13.
//
//

#include "Ball.h"

Ball::Ball(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSeedRandom();
}

void Ball::setup(float _gravity, float _damping, ofColor _ballColor, ofVec2f _vel, ofVec2f _pos, float _r){
    gravity = _gravity;
    damping = _damping;
    ballColor = _ballColor;
    vel=_vel;
    pos=_pos;
    r=_r;
}

void Ball::update(){
    pos += vel;
    vel.y += gravity;

    if(pos.x<0+r || pos.x > ofGetWindowWidth()-r) vel.x *= -1;
    if(pos.y > ofGetWindowHeight()-r) {
        pos.y = ofGetWindowHeight()-r-2;
        vel.y *= -damping;
    }

    

}

void Ball::draw(){
    ofSetColor(ballColor);
    ofCircle(pos, r);
}