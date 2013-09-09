//
//  Ball.cpp
//  vectors
//
//  Created by Michael Kahane on 9/6/13.
//
//

#include "Ball.h"

Ball::Ball(){    
    ofSeedRandom();    
    ballColor= ofColor(0,0,0,0);
    xVelocity = .04;
    yVelocity = .2;
    pos.x = ofRandom(-ofGetWindowHeight()/2,ofGetWindowHeight());
    pos.y = ofRandom(-ofGetWindowHeight()*2,-20);
    
}

void Ball::update(){
    pos.x += xVelocity * 10;
    pos.y += yVelocity * 10;
    
    if(pos.y>ofGetWindowHeight()+r){
        pos.x = ofRandom(-ofGetWindowHeight()/2,ofGetWindowHeight()+ofGetWindowHeight()/2);
        pos.y = ofRandom(-ofGetWindowHeight()/4,-30);
        yVelocity = .2;
        ballColor= ofColor(0,0,225,200);
    }
}

void Ball::draw(){
    ofSetColor(ballColor);
    ofCircle(pos.x,pos.y, r);
}