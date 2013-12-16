#pragma once

#include "ofMain.h"
#include "ofxFluid.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    ofxFluid fluid, fluid2, fluid3, fluid4, fluid5, fluid6, fluid7, fluid8;
    vector<ofxFluid> fluidList; 
    ofVec2f oldM;
    int     width,height;
    bool    bPaint, bObstacle, bBounding, bClear;
};