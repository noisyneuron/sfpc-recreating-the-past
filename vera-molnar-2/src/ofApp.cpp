#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 8);
    
    fbo.begin();
    ofClear(30,30,30,255);
    fbo.end();
    doDraw = false;
    
    colors[0] = ofColor(200, 172, 192);
    colors[1] = ofColor(132, 213, 19);
    colors[2] = ofColor(12, 148, 156);
    colors[3] = ofColor(198, 192, 29);
    colors[4] = ofColor(97, 104, 184);
    colors[5] = ofColor(73, 192, 165);
    colors[6] = ofColor(98, 59, 193);
    
    for(int i=0; i<density*density; i++) {
        colIdx[i] = (int)ofRandom(0, 7);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(doDraw) {
        
        fbo.begin();
//        ofBackground(30,30,30,255);
        
        float drawArea = ofGetWidth() - 2*padding;
        float unitSize = drawArea / density;
        
        
        for(int i=0; i<density; i++) {
            for(int j=0; j<density; j++) {
                int col = colIdx[i*density + j];
                SquareUnit s(padding + i*unitSize, padding + j*unitSize, unitSize, unitSize, 30, colors[col]);
                s.draw();
            }
        }
        doDraw = false;
        fbo.end();
    }
    
    
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='s') {
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
    } else if (key=='d') {
        doDraw = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
