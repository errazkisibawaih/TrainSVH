//
//  CSegment.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef CSEGMENT_H_
#define CSEGMENT_H_

class CSegment {
public:
    int id_segment;
    int id_point_annex_ini;
    int id_point_annex_fin;
    int id_arc;
    CSegment();
    virtual ~CSegment();
};

#endif /* CSEGMENT_H_ */
