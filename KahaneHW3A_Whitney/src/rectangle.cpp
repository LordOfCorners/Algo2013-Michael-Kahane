//
//  rectangle.cpp
//  Rectangles
//
//  Created by Michael Kahane on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle(){
}

void Rectangle::setup(ofVec2f _pos, ofVec2f _newPos, ofColor _color, int _width, int _height, ofVec2f _newPos2, ofVec2f _newPos3){
    pos = _pos;
    newPos = _newPos;
    newPos2 = _newPos2;
    newPos3 = _newPos3;
    color=_color;
    height = _height;
    width = _width;
}

void Rectangle::update(){

}

void Rectangle::draw(){
    float sinOfTime = sin( ofGetElapsedTimef() * 2 );
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 20, 80);

    ofEnableAlphaBlending();
    ofSetColor(color);
    ofRect(pos.x,pos.y,width + sinOfTimeMapped,height+sinOfTimeMapped);
}

void Rectangle::interpolateByPct(ofVec2f _posA, ofVec2f _posB, float myPct){
    pct = myPct;
    posA=_posA;
    posB=_posB;
    pct = powf(myPct, 4);
    pos.x = (1-pct) * posA.x + pct *posB.x;
    pos.y = (1-pct) * posA.y + pct *posB.y;
}