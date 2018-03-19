//
//  SquareUnit.cpp
//  vera-molnar-1
//
//  Created by Sukanya Aneja on 2/27/18.
//

#include "SquareUnit.hpp"

SquareUnit::SquareUnit(float _x, float _y, float _w, float _h, int _count, int _offsetIdx) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    count = _count;
    offsetIdx = _offsetIdx;
}

void SquareUnit::draw() {
    ofNoFill();
//    ofSetColor(0, 0, 0);
    ofSetColor(123,117,105);
    ofSetLineWidth(thickness);
    float space = w*0.5 / count;
    float randIdx = (int)ofRandom(0, count);
    
    for(int i=0; i<count; i++) {
        float dist = i*space;
        
        ofPoint a(x + dist, y + dist);
        ofPoint b(x + w - dist, y + dist);
        ofPoint c(x + w - dist, y + h - dist);
        ofPoint d(x + dist, y + h - dist);
        
//        if(i == randIdx) { //or (i == offsetIdx)
//            a.x += ofRandom(-randomness, randomness);
//            a.y += ofRandom(-randomness, randomness);
//            b.x += ofRandom(-randomness, randomness);
//            b.y += ofRandom(-randomness, randomness);
//            c.x += ofRandom(-randomness, randomness);
//            c.y += ofRandom(-randomness, randomness);
//            d.x += ofRandom(-randomness, randomness);
//            d.y += ofRandom(-randomness, randomness);
//        }
        
        float scale = (float)(count - i)/(float)count;
        a.x += ofRandom(-randomness*scale, randomness*scale);
        a.y += ofRandom(-randomness*scale, randomness*scale);
        b.x += ofRandom(-randomness*scale, randomness*scale);
        b.y += ofRandom(-randomness*scale, randomness*scale);
        c.x += ofRandom(-randomness*scale, randomness*scale);
        c.y += ofRandom(-randomness*scale, randomness*scale);
        d.x += ofRandom(-randomness*scale, randomness*scale);
        d.y += ofRandom(-randomness*scale, randomness*scale);
        
        if(ofRandom(0,1) > 0.85 ) {
            ofDrawLine(a, b);
            ofDrawLine(b, c);
            ofDrawLine(c, d);
            ofDrawLine(d, a);
        }

        
    }
}

