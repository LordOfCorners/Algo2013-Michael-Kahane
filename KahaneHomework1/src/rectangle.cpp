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

void Rectangle::setup(ofPoint _pos, ofColor _color, float _catchUpSpeed, int _width, int _height){
    pos.x = _pos.x;
    pos.y = _pos.y;
    color=_color;
    catchUpSpeed = _catchUpSpeed;
    height = _height;
    width = _width;
}

void Rectangle::update(float _rate){
    rate = _rate;
    pos.x+=rate;
    if(!acrossScreen && pos.x>ofGetWindowWidth()){
        acrossScreen=true;
        acrossScreenTime=ofGetElapsedTimef();;
    }
    if(pos.x>ofGetWindowWidth()){
        pos.x = 0;
    }
}

void Rectangle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(color);
    ofRect(pos.x,pos.y,width,height);
}

void Rectangle::displayInfo(ofPoint _infoPos){
    ofSetColor(color);
    infoPos=_infoPos;
    string ins = ofToString((rate*60)/110) + " inches per second";
    ofDrawBitmapString(ins, infoPos.x, infoPos.y+10);
    
    string mph = ofToString(((rate*60))/110*.0568181818)+ " miles per hour";
    ofDrawBitmapString(mph, infoPos.x, infoPos.y+20);
    
    string acrossScreen = ofToString( (ofGetWindowWidth()/110) / ((rate*60)/110)) + " seconds to move across the screen";
    ofDrawBitmapString(acrossScreen, infoPos.x, infoPos.y+30);
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    float dist = ofDist(catchX,catchY,pos.x,pos.y);
    width = dist+5;
    height = dist+5;
}
