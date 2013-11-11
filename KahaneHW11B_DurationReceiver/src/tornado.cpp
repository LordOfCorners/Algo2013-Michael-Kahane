//
//  tornado.cpp
//  KahaneHW3C_phenomenon
//
//  Created by Michael Kahane on 9/17/13.
//
//

#include "tornado.h"


Tornado::Tornado(){
}

void Tornado::setup(float _timer){
    timer=_timer;
}

void Tornado::update(){
    radius += 0.05;
    y+=0.2;
    if(pointList.size() <2000){
        float angle = (ofGetElapsedTimef()-timer)*1.5;
        
        float x = radius*cos(angle);
        float z = radius*sin(angle);
        
        ofPoint pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        
        pointList.push_back(pos);
    }
}

void Tornado::draw(float lineThickness){

    ofPushMatrix();
//    ofTranslate(ofRandom(-2,2),ofRandom(-2,2));
    ofNoFill();
    ofBeginShape();
//    ofSetLineWidth(lineThickness);
    for(int i=0;i<pointList.size();i++){
        ofVertex(pointList[i]);
    }
    ofEndShape();
    
    ofPopMatrix();


}
