//
//  SquareUnit.cpp
//  vera-molnar-1
//
//  Created by Sukanya Aneja on 2/27/18.
//

#include "SquareUnit.hpp"

SquareUnit::SquareUnit(float _x, float _y, float _w, float _h, int _count, ofColor _c) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    count = _count;
    c = _c;
}

void SquareUnit::draw() {
    ofNoFill();
    ofSetColor(c);
    ofSetLineWidth(thickness);
    ofPolyline l;

    l.addVertex(ofVec2f(x + ofRandom(-randomness, randomness), y + ofRandom(-randomness, randomness)));
    l.addVertex(ofVec2f(x + w + ofRandom(-randomness, randomness), y + ofRandom(-randomness, randomness)));
    l.addVertex(ofVec2f(x + w + ofRandom(-randomness, randomness), y + w + ofRandom(-randomness, randomness)));
    l.addVertex(ofVec2f(x + ofRandom(-randomness, randomness), y + w + ofRandom(-randomness, randomness)));
    
    l.close();
    l.draw();
    
}

