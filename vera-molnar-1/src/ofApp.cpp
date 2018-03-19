#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 8);
    
    fbo.begin();
    ofClear(239,235,224,255);
    fbo.end();
    doDraw = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(doDraw) {
        
        fbo.begin();
//        ofBackground(255, 255, 255, 255);
        
        float drawArea = ofGetWidth() - 2*padding;
        float unitSize = drawArea / density;
        
        
        for(int i=0; i<density; i++) {
            for(int j=0; j<density; j++) {
                SquareUnit s(padding + i*unitSize, padding + j*unitSize, unitSize, unitSize, 6, 6);
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
