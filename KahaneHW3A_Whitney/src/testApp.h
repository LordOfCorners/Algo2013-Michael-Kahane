#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "rectangle.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxPostProcessing post;
    ofEasyCam cam;
    ofLight light;
    
    Rectangle blueRect, orangeRect, whiteRect;
    vector<Rectangle> rectList;
		
};
