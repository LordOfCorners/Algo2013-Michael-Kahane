//
//  rectangle.cpp
//  Rectangles
//
//  Created by Michael Kahane on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
}

void Rectangle::update(){
 //   pos.x = pos.x + ofRandom(-1,1);
}

void Rectangle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(100,100,255,255*.40);
    ofRect(pos.x,pos.y,20,20);

}

void Rectangle::interpolateByPct(float myPct){
    pct = myPct;
    
    pct = powf(myPct, 4);
    pos.x = (1-pct) * posA.x + pct *posB.x;
    pos.y = (1-pct) * posA.y + pct *posB.y;
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    float catchUpSpeed = 0.06f;
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
