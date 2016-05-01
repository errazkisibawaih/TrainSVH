//
//  CPoint3f.cpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#include "CPoint3f.hpp"
#include "consts.h"
#include <stdio.h>
using namespace std;

CPoint3f::CPoint3f(const float &x, const float &y, const float &z):X(x), Y(y), Z(z) {}

CPoint3f::CPoint3f(const float &a):X(a), Y(a), Z(a){}

CPoint3f::CPoint3f():X(RNOVA), Y(RNOVA), Z(RNOVA) {}

CPoint3f::CPoint3f(const CPoint3f &p):X(p.X), Y(p.Y), Z(p.Z) {}

string CPoint3f::toString(){
    char data[1024] = "";
    sprintf(data, "`->coord. : %f %f %f", X, Y, Z);
    string str(data);
    return str;
}

