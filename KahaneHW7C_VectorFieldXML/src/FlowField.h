//
//  FlowField.h
//  VectorField
//
//  Created by Charlie Whitney on 10/7/13.
//
//

#pragma once
#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField {
public:
    FlowField();
    
    void setup( int width, int height, int res );
    void setRandom();
    void setPerlin();
    void sinYsinX();
    void sinXcosY();
    
    void negYposX();
    
    
    void draw();
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos );
    
    vector<VectorList>  flowList;
    int                 fieldWidth, fieldHeight, resolution;
};