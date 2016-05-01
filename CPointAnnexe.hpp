//
//  CPointAnnexe.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef CPOINTANNEXE_H_
#define CPOINTANNEXE_H_
#include "CPoint3f.hpp"
class CPointAnnexe:public CPoint3f
{
public:
    int id_point_annex;
    CPointAnnexe();
    CPointAnnexe(int, const CPoint3f&);
    std::string toString();
    virtual ~CPointAnnexe();
};

#endif /* CPOINTANNEXE_H_ */