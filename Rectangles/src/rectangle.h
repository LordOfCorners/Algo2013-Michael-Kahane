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
    
        ofPoint pos; 
};