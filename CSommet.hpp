//
//  CSommet.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef CSOMMET_H_INCLUDED
#define CSOMMET_H_INCLUDED
#include <vector>
#include <string>
#include "CPoint3f.hpp"
class CSommet:public CPoint3f
{
public:
    int id_sommet;
    std::vector<int> id_arc_entrant;
    std::vector<int> id_arc_sortant;
    CSommet();
    CSommet(int);
    CSommet(int, CPoint3f);
    CSommet(float, float, float);
    std::string toString();
protected:
    
private:
    
};
#endif // CSOMMET_H_INCLUDED
