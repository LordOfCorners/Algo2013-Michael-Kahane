//
//  tornado.cpp
//  KahaneHW3C_phenomenon
//
//  Created by Michael Kahane on 9/17/13.
//
//

#include "tornado.h"


Tornado::Tornado(){
    color = ofColor(200,200,200);
}

void Tornado::setup(float _timer){
    timer=_timer;
}

void Tornado::update(){
    radius += 0.05;
    y+=0.2;
    if(pointList.size() <1000){
        float angle = (ofGetElapsedTimef()-timer)*3.5;
        
        float x = radius*cos(angle);
        float z = radius*sin(angle);
        
        ofPoint pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        
        pointList.push_back(pos);
    }
}

void Tornado::draw(){

    ofPushMatrix();
    ofTranslate(ofRandom(-2,2),ofRandom(-2,2));
    ofSetColor(color);
    ofNoFill();
    ofBeginShape();
    for(int i=0;i<pointList.size();i++){
        ofVertex(pointList[i]);
    }
    ofEndShape();
    
    ofPopMatrix();


}
