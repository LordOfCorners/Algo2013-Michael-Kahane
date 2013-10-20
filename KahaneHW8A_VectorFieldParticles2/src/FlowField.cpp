//
//  FlowField.cpp
//  VectorField
//
//  Created by Charlie Whitney on 10/7/13.
//
//

#include "FlowField.h"

FlowField::FlowField() {
    
}

void FlowField::setup( int width, int height, int res ) {
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    // Make a big list of forces.  We will store them in a 2 dimensional vector.
    for( int y=0; y<rows; y++){
        VectorList myList;
        flowList.push_back( myList );
        
        for( int x=0; x<rows; x++){
            ofVec2f dir(1,0);
            flowList[y].push_back( dir );
        }
    }
}

ofVec2f FlowField::getForceAtPosition( ofVec2f pos ){
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    int xVal = ofClamp( pctX * cols, 0, cols-1 );
    int yVal = ofClamp( pctY * rows, 0, rows-1 );
    
    ofVec2f newPos;
    newPos.set( flowList[yVal][xVal] );
    
    return newPos;
}




void FlowField::draw() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            drawVectorAt( flowList[y][x], np );
        }
    }
}

//help from https://sites.google.com/site/ofauckland/examples
void FlowField::update(ofVideoGrabber vid) {
    for( int y=0; y<flowList.size(); y+=1){
        for( int x=0; x<flowList[y].size(); x+=1){
    
            //get pixel color
            int i = ((y*resolution)*ofGetWindowWidth()+(x*resolution))*3;
            int r = vid.getPixels()[i+0];
            int g = vid.getPixels()[i+1];
            int b = vid.getPixels()[i+2];
            
            //calculate brightness
            float br = (r+b+g) / 765.0;
            
            //use HSB color
            ofSetColor(ofColor::fromHsb(br*255,255,255));
            
            //calculate sine and cosine of brightness
            float co = cos(br*TWO_PI);
            float si = sin(br*TWO_PI);
            ofVec2f vec = ofVec2f(((x*resolution)+5*co)-((x*resolution)-5*co), ((y*resolution)+5*si) -((y*resolution)-5*si));
//            vec.normalize();
//            vec*=3;
            flowList[y][x].set(vec);
            
            // don't let the force get too small
            
            float vecSize =flowList[y][x].length();
            
            if( vecSize < 1.0){
                flowList[y][x].normalize();
            }else if( vecSize > 20.0 ){
                flowList[y][x].normalize() * 20.0;
            }
            
            // lets also limit the max

        }
    }
}



void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos ) {
    ofVec2f np = pos - (vec.normalized()) * 5.0;
    drawVector( np, np + vec.normalized() * 10.0, 5, 3 );
}

/**
 * This is a complicated one!  It's a translation of the one right out of the Cinder source, no need to understand it,
 * but it's an interesting one to look at anyway!
 * https://github.com/cinder/Cinder/blob/master/src/cinder/gl/gl.cpp line 915 if you're interested
 */
void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
	const int NUM_SEGMENTS = 32;
	float lineVerts[3*2];
	ofVec3f coneVerts[NUM_SEGMENTS+2];
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
	lineVerts[0] = start.x; lineVerts[1] = start.y; lineVerts[2] = start.z;
	lineVerts[3] = end.x; lineVerts[4] = end.y; lineVerts[5] = end.z;
	glDrawArrays( GL_LINES, 0, 2 );
	
	// Draw the cone
	ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
	ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
	ofVec3f up = axis.crossed( left ).normalized();
    
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = ofVec3f( end + axis * headLength );
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = (float)s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	// draw the cap
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = end;
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	glDisableClientState( GL_VERTEX_ARRAY );
}