#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void analyseImage();
    void chunkImage();
    
    ofImage img;
    vector <ofVec2f> gradients;
    vector <float> brights;
    
    vector <ofVec2f> gradientsChunked;
    vector <float> brightsChunked;
    
    ofImage moons [15];
    ofFbo fbo;
    
    float gridSize;
    float iw;
    float ih;
    
};
