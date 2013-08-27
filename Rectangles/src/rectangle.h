//
//  rectangle.h
//  Rectangles
//
//  Created by Michael Kahane on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
    public:
        Rectangle();
    
        void update();
        void draw();
    
        void interpolateByPct(float myPct);
    
        void xenoToPoint(float catchX, float catchY);
    
        ofPoint pos;
    
        //for interpolation
        ofPoint posA, posB;        
    
        float pct;
};