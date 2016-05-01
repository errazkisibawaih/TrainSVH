//
//drawrails.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef drawrails_hpp
#define drawrails_hpp

#include <stdio.h>
using namespace std;

#endif /* drawrails_hpp */

class drawrails {
    public :
    CGraphe graphe;
    drawrails(CGraphe graphe);
    void  defineWindow(const string & title);
    void initialize(const string & title);
    void drawr();
}; 
