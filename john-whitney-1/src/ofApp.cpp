#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float ang1 = ofRandom(0,1) * TWO_PI;
    float ang2 = ofRandom(0,1) * TWO_PI;
    center = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    ofSoundStreamSetup(2, 0);
    ofSoundStreamListDevices();
    ofSoundStreamStop();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::drawTriangles(ofPoint center, float rotation, float timeOffset){
    int count = 15;
    float time = ofGetElapsedTimef() + timeOffset;
    
    // --- modify whether inside or outside radius changes more
    float t = time*0.15;
    float radiusMod = sin(t) + sin(3*t)/3 + sin(5*t)/5 + sin(7*t)/7 + sin(9*t)/9;
    
    radiusMod = ofMap(radiusMod, -1, 1, 0, 1);
    
    
    for(int i=0;i<count;i++) {
        
        float offset = 5;
        
        float independence = 50*sin(0.1*time+i  );
        independence = abs(pow(sin(time*0.08), 23));
        offset += 50*independence;
        
        center.x += offset * sin(0.3*time + independence);
        center.y += offset * sin(0.9*time + independence);
        
//        ofDrawEllipse(center.x, center.y, 3, 3);
        
        
        // --- variable line thickness.. make lines look better?
        float thickness = (float)(count-i)*0.45;
        
        float radius = ofLerp(count-i, i+1, radiusMod) * 20;
        float sides = 3;
        
        ofPolyline l;
        for(int j=0;j<sides;j++) {
            float angle = rotation + j/sides * TWO_PI;
            float x = center.x + radius*cos(angle);
            float y = center.y + radius*sin(angle);
            l.addVertex(ofPoint(x,y));
        }
        l.close();
        
        
        
        ofMesh m;
        m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        for (int i = 0; i < l.size()+1; i++){
            
            int i_m_1 = i-1;
            int i_p_1 = i+1;
            if (i_m_1 < 0) i_m_1 += l.size();
            if (i_p_1 >= l.size()) i_p_1 -= l.size();
            ofPoint prev = l[i_m_1]; // polyline lets you grab vertex like array
            ofPoint next = l[i_p_1];
            // get angle bisector vector / normal
            ofPoint diff = (next - prev);
            diff = diff.getNormalized();
            diff.rotate(90, ofPoint(0,0,1));  // rotate 90 on the z axis.
            
            // thickness is the magnitude to travel in directipn of diff
            m.addVertex(l[i % l.size()] + diff * thickness*0.5);
            m.addVertex(l[i % l.size()] - diff * thickness*0.5);
            
        }
        
//        thickness +=  + mouseX*0.1;
//        m.drawWireframe();
        m.draw();
        
        
        //l.draw();
    }
}



//--------------------------------------------------------------
void ofApp::drawDots(){
    int count = 300;
    float time = ofGetElapsedTimef() * 0.1;
    for(int i=0; i<count; i++) {
        ofPoint center(ofGetWidth()/2, ofGetHeight()/2);
        float angle = ofMap(sin(time+i), -1, 1, 0, TWO_PI);
        angle = ofMap(i,0,count,0,TWO_PI);
        float radius = ofMap(sin(2.5*time+i*0.1), -1, 1, 300, 600);
        float offset = sin(time + i);
        offset = sin(offset + time);
        radius *= sin(time + offset);
        float x = center.x + radius*sin(angle);
        float y = center.y + radius*cos(angle);
        ofDrawEllipse(x, y, 2, 2);
    }
}


//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer outBuffer) {
    for(int i=0; i<outBuffer.getNumFrames(); i++) {
        outBuffer[i] = ofRandom(0, 1);
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(0,0,255);

    
    float time = ofGetElapsedTimef();
    float radius = 120 + ofMap(ofNoise(ang1, ang2, cos(time*0.05), sin(time*0.05)), 0, 1, -100, 100);
    
    float speed = sin(time*0.2) * 0.002;
    
    ang1 += speed;
    ang2 -= speed;

    center1.x = center.x + radius*sin(2.3*ang1);
    center1.y = center.y + radius*sin(ang1);

    center2.x = center.x + radius*sin(ang2);
    center2.y = center.y + radius*sin(2.7*ang2);

    
    drawTriangles(center1, 0, 0);
    drawTriangles(center2, TWO_PI/6, 10);
    
//    ofSetColor(0,255,0);
//    drawDots();
//    drawTriangles(ofPoint(ofGetWidth()*.2, ofGetHeight()*.6), TWO_PI/3, 7);
//    drawTriangles(ofPoint(ofGetWidth()*.8, ofGetHeight()*.4), TWO_PI/2, 13);
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
