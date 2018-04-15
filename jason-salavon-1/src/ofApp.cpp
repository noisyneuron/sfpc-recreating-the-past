#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofDirectory dir;
    dir.listDir("flags");
    
    for(int i=0; i<dir.size() ; i++) {
        string fileName = dir.getPath(i);
        ofImage temp;
        temp.load(fileName);
        //temp.setImageType(OF_IMAGE_COLOR);
        imgs.push_back(temp);
    }
    
    mix.allocate(800, 800, OF_IMAGE_COLOR);
    
    for(int i=0; i<800; i++) {
        for(int j=0; j<800; j++) {
            
            float r = 0;
            float g = 0;
            float b = 0;

            for(int k=0; k<imgs.size(); k++) {
                ofColor c = imgs[k].getColor(i, j);
                r += c.r;
                g += c.g;
                b += c.b;
            }

            r = r / imgs.size();
            g = g / imgs.size();
            b = b / imgs.size();
            mix.setColor(i, j, ofColor(r,g,b, 255));
        }
    }
    
    
    mix.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    mix.draw(0, 0);
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
