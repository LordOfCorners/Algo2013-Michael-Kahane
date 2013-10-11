#pragma once

#include "ofMain.h"
#include "particle.h"
#include "attractor.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void addAttractor();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector <particle> particles;
        vector <attractor> attractorList;

    
    ofVec2f forcePos1, forcePos2, forcePos3, forceVel1, forceVel2, forceVel3;
		
};
