#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableAntiAliasing();
    img.load("ken-blur.jpg");
    iw = img.getWidth();
    ih = img.getHeight();
    
    gridSize = 64;
    fbo.allocate(gridSize, gridSize, GL_RGBA);
    
    // draw mesh around center of grid unit
    mesh.addVertex(ofPoint(-1*gridSize, -1*gridSize));
    mesh.addColor(ofFloatColor(0., 0., 0.));
    
    mesh.addVertex(ofPoint(1*gridSize,-1*gridSize));
    mesh.addColor(ofFloatColor(0., 0., 0.));
    
    mesh.addVertex(ofPoint(1*gridSize, 1*gridSize));
    mesh.addColor(ofFloatColor(1., 1., 1.));
    
    mesh.addVertex(ofPoint(-1*gridSize,1*gridSize));
    mesh.addColor(ofFloatColor(1., 1., 1.));
    
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);

    mesh.addIndex(0);
    mesh.addIndex(2);
    mesh.addIndex(3);
    
    updateFbo(ofVec2f(0,0));
    
    analyseImage();
    chunkImage();
}

//--------------------------------------------------------------
void ofApp::analyseImage(){
    for(int i=0; i<iw; i++) {
        for(int j=0; j<ih; j++) {
            
            float bright [3][3];
            
            for(int m=-1; m<=1; m++) {
                for(int n=-1; n<=1; n++) {
                    
                    // initilise it to 0
                    // safeguard for corner and edge cases
                    bright[m+1][n+1] = 0;
                    
                    int x = i+m;
                    int y = j+n;
                    
                    if(x >=0 && x < iw && j >= 0 && j < ih) {
                        float b = img.getColor(x, y).getBrightness();
                        bright[m+1][n+1] = b;
                        if(m==0&n==0) {
                            brights.push_back(b);
                        }
                    }
                    
                    
                    
                }
            }
            
            float brightTop = bright[0][0] + bright[1][0] + bright[2][0];
            float brightBottom = bright[0][2] + bright[1][2] + bright[2][2];
            
            float brightLeft = bright[0][0] + bright[0][1] + bright[0][2];
            float brightRight = bright[2][0] + bright[2][1] + bright[2][2];
            
            ofVec2f dir = ofVec2f(brightRight - brightLeft, brightTop - brightBottom);
            gradients.push_back(dir);
            
        }
    }
}


//--------------------------------------------------------------
void ofApp::chunkImage(){

    for(int i=0; i<iw/gridSize; i++) {
        for(int j=0; j<ih/gridSize; j++) {
            float b = 0;
            ofVec2f d = ofVec2f(0,0);
            
            for(int x=0; x<gridSize; x++) {
                for(int y=0; y<gridSize; y++) {
                    
                    b += brights[ (i*gridSize+x)*iw + (j*gridSize+y)];
                    d += gradients[ (i*gridSize+x)*iw + (j*gridSize+y)];
                }
            }
            
            b = b/(gridSize*gridSize);
            d /= (gridSize*gridSize);
//            cout << b << endl;
            brightsChunked.push_back(b);
            gradientsChunked.push_back(d);
        }
    }
}


//--------------------------------------------------------------
void ofApp::updateFbo(ofVec2f dir){
    
    ofVec2f anchor = ofVec2f(-1,0);
    fbo.begin();
    ofClear(0,0,0,255);
    ofPushMatrix();
    ofTranslate(gridSize*.5, gridSize*0.5);
    ofRotateZ(anchor.angle(dir));
    mesh.draw();
    ofPopMatrix();
    fbo.end();
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    int stepX = iw/gridSize;
    int stepY = ih/gridSize;

    for(int i=0; i<stepX; i++) {
        for(int j=0; j<stepY; j++) {

            float b = brightsChunked[i*stepX + j];
            ofVec2f d = gradientsChunked[i*stepY + j];
            d.normalize();
            d *= gridSize/2;

            int idx = (int)ofMap(b, 0, 255, 0, 14);


            ofVec2f anchor = ofVec2f(-1,0);


            ofPushMatrix();

            updateFbo(d);
            fbo.draw(i*gridSize, j*gridSize, gridSize, gridSize);

            //            ofSetColor(255,0,0);
            //            ofRotateZ(-anchor.angle(d));
            //            ofDrawLine(0,0,d.x,d.y);

            ofPopMatrix();
        }
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
