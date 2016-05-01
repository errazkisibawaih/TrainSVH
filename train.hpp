//
//  train.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 24/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef train_hpp
#define train_hpp

#include <stdio.h>
#include "CPoint3f.hpp"
#include "CArc.hpp"
#include "CPointAnnexe.hpp"

class train{
    
public:
    CArc ArcActuel;			//arc sur lequel se déplace le train
    double Vitesse;			    //vitesse de déplacement
    CPoint3f Coord;			//position courante
    int PointAnnexeP;			//indice du prochain point annexe à atteindre
    
    
    CArc ArcProchain;
    
    
    
    train();
    ~train();
    
    
};


#endif /* train_hpp */
