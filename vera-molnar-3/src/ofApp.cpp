#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    unitSize = (ofGetWidth() - density*2*spacing)/density;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(seed);
//    ofDisableBlendMode();
    ofBackground(148,156,158);
    ofSetColor(255);
    for(int i=0;i<density;i++) {
        for(int j=0; j<density; j++) {
            float x = (2*i + 1)*spacing + unitSize*i;
            float y = (2*j + 1)*spacing + unitSize*j;
            ofDrawRectangle(x, y, unitSize, unitSize);
        }
    }
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(148,156,158);
    for(int i=0;i<density;i++) {
        for(int j=0; j<density; j++) {
            float x = (2*i + 1)*spacing + unitSize*i;
            float y = (2*j + 1)*spacing + unitSize*j;
            x += ofRandom(-randomness,randomness);
            y += ofRandom(-randomness,randomness);
            ofDrawRectangle(x, y, unitSize, unitSize);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='s') {
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
    } else {
        seed = (int)ofRandom(0,18701213);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
