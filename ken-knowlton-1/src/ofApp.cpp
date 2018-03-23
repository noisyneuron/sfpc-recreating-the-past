#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("ken.jpg");
    cout << img.getWidth() << " " << img.getHeight() << endl;
    
    fbo.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    
    gridSize = 32;
    
    for(int i=0; i<15; i++) {
        if(i==0 || i == 14) {
            moons[i].load(to_string(i) + ".jpg");
        } else {
            moons[i].load(to_string(i) + "l.jpg");
        }
    }
    
    
    
    fbo.begin();
    ofClear(0,0,0,255);
    
    ofSetColor(255);
    
    for(int i=0; i<img.getWidth(); i+=gridSize) {
        for(int j=0; j<img.getHeight(); j+=gridSize) {

            float brightness = 0;
            
            for(int m=0; m<gridSize; m++) {
                for(int n=0; n<gridSize; n++) {
                    brightness += img.getColor(m+i, n+j).getBrightness();
                }
            }
            
            brightness = brightness / (gridSize * gridSize);
            
            int idx = (int)ofMap(brightness, 0, 255, 0, 15);
            moons[idx].draw(i, j, gridSize, gridSize);
        }
    }
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.draw(0,0);
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
