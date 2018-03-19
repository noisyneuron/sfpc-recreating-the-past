#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex(); // what does this do?
    
    font.load("Devanew.ttf", 200);
    
    str = "kla";
    bounds = font.getStringBoundingBox(str, 0, 0);
    aspectRatio = bounds.getWidth()/bounds.getHeight();
    fbo.allocate(bounds.getWidth(), bounds.getHeight(), GL_RGBA);

    cout << bounds.getWidth() << endl;
    cout << bounds.getHeight() << endl;
    
    fbo.begin();
    ofClear(0);
    // transparent background so alpha can indicate 'in' or 'out' of shape
    ofBackground(0,0);
    ofSetColor(255);
    font.drawString(str, 0, bounds.getHeight());
    fbo.end();
    
    
    // is the folder necessary / is it actually specifying glsl version?
    shader.load("shadersGL3/shader");
    
    
    // OF automatically sends normalised `texcoords` to shader
    // how does this work with multiple shaders?
    // what is variable for coords called?
    shader.setUniformTexture("tex", fbo.getTexture(), 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    shader.begin();
    
    float time = ofGetElapsedTimef();
    float y = 0;
    
    for(int i=0; i<20; i++) {
        
        float w = ofGetWidth() / float(i+1);
        float h = w / aspectRatio;
        
        for(int j=0; j<=i; j++) {
            shader.setUniform1f("time", time);
            fbo.draw(j*w, y, w, h);
        }
        y += h;
    }

    
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
