//
//  CPoint3f.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef CPOINT3_H_
#define CPOINT3_H_
#include <string>
class CPoint3f {
public:
    float X;
    float Y;
    float Z;
    CPoint3f(const float&, const float&, const float&);
    CPoint3f(const float&);
    CPoint3f();
    CPoint3f(const CPoint3f&);
    std::string toString();
};

#endif /* CPOINT3_H_ */
