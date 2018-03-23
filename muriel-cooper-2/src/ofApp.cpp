#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex(); // what does this do?
    shader.load("shadersGL3/shader");
    
    size = 200;
    font.load("Quarto.otf", size);
    
    str[0] = "IM";
    str[1] = "PER";
    str[2] = "MAN";
    str[3] = "ENCE";
    
    cols[0] = ofColor(186,36,34);
    cols[1] = ofColor(183,40,110);
    cols[2] = ofColor(102,51,126);
    cols[3] = ofColor(67,60,126);
    
    
    for(int i=0; i<4; i++) {
        bounds[i] = font.getStringBoundingBox(str[i], 0, 0);
        cout << bounds[i].getWidth() << "; " << bounds[i].getHeight() << endl;
        aspectRatio[i] = bounds[i].getWidth()/bounds[i].getHeight();
        buffer1[i].allocate(bounds[i].getWidth(), bounds[i].getHeight(), GL_RGBA);
        buffer2[i].allocate(bounds[i].getWidth(), bounds[i].getHeight(), GL_RGBA);
        
        buffer1[i].begin();
        ofClear(0);
        ofBackground(220,0);
        ofSetColor(cols[i]);
        font.drawString(str[i], 0, bounds[i].getHeight());
        buffer1[i].end();
        
        buffer2[i].begin();
        ofClear(0);
        buffer2[i].end();
        
        shader.setUniformTexture("tex", buffer1[i].getTexture(), 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(220);
    float t = ofGetElapsedTimef();
    time = t < 8 ? 0 : t;
    
    for(int i=0; i<4; i++) {
        
        buffer2[i].begin();
        
        shader.begin();
        
        shader.setUniform1f("time", time);
        
        buffer1[i].draw(0, 0, bounds[i].getWidth(), bounds[i].getHeight());
        
        shader.end();
        
        buffer2[i].end();
        
        buffer2[i].draw(0,.9*size*i);

        shader.setUniformTexture("tex", buffer2[i].getTexture(), 0);
        buffer1[i] = buffer2[i];
    }
    
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
