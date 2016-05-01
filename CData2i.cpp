//
//  CData2i.cpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//


#include "CData2i.hpp"
#include "consts.h"
CData2i::CData2i(int x, int y):colonne_1(x), colonne_2(y) {
}
CData2i::CData2i():colonne_1(NOVAL), colonne_2(NOVAL) {
}
CData2i::CData2i(const CData2i &data2i):colonne_1(data2i.colonne_1), colonne_2(data2i.colonne_2){
    
}
