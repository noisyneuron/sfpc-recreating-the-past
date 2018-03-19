//
//  SquareUnit.hpp
//  vera-molnar-1
//
//  Created by Sukanya Aneja on 2/27/18.
//

#ifndef SquareUnit_hpp
#define SquareUnit_hpp

#include <stdio.h>
#include "ofMain.h"

class SquareUnit {
public:
    void setup();
    void update();
    void draw();
    
    float thickness = 0.5;
    float randomness = 8;
    
    SquareUnit(float _x, float _y, float _w, float _h, int _count, int _offsetIdx);
    
private:
    float x;
    float y;
    float w;
    float h;
    int count;
    int offsetIdx;
};
#endif /* SquareUnit_hpp */
