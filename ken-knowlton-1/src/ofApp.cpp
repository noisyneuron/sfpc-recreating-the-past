#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    elephant.load("ken.jpg");
    cout << elephant.getWidth() << " " << elephant.getHeight() << endl;
    
    fbo.allocate(elephant.getWidth(), elephant.getHeight(), GL_RGBA);
    
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
    
    for(int i=0; i<elephant.getWidth(); i+=gridSize) {
        for(int j=0; j<elephant.getHeight(); j+=gridSize) {

            float brightnessLeft = 0;
            float brightnessRight = 0;
            
            for(int m=0; m<gridSize/2; m++) {
                for(int n=0; n<gridSize; n++) {
                    brightnessLeft += elephant.getColor(m+i, n+j).getBrightness();
                }
            }
            
            for(int m=gridSize/2; m<gridSize; m++) {
                for(int n=0; n<gridSize; n++) {
                    brightnessRight += elephant.getColor(m+i, n+j).getBrightness();
                }
            }
            
            float totalBrightness = (brightnessLeft+brightnessRight) / (gridSize*gridSize);
            int idx = (int)ofMap(totalBrightness, 0, 255, 0, 15);
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
