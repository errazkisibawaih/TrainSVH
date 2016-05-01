//
//  CGraphe.hpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#ifndef CGRAPHE_H_
#define CGRAPHE_H_
#include <vector>
#include <string>
#include "CSegment.hpp"
#include "CArc.hpp"
#include "CSommet.hpp"
#include "CPointAnnexe.hpp"
#include "CDonneesGraphe.hpp"
#include "consts.h"
class CGraphe {
public:
    
    
    CGraphe(CDonneesGraphe gdata);
    void buildGrapheObjectsFromData(CDonneesGraphe gdata);
    void buildArcsFromData(CDonneesGraphe gdata);
    void buildPointsAnnexesFromData(CDonneesGraphe gdata);
    void buildSommetsFromData(CDonneesGraphe gdata);
    void buildExtent();
    
    
    std::vector<CSommet> list_sommet;
    int nb_sommet;
    std::vector<CArc> list_arc;
    int nb_arc;
    std::vector<CPointAnnexe> list_point_annexe;
    int nb_point_annex;
    std::vector<CArc> getListArcEntrantDansSommet(const CSommet &sommet);
    std::vector<CArc> getListArcSortantDuSommet(const CSommet &sommet);
    std::vector<CPointAnnexe> getListPointAnnexeArc(const CArc &arc);
    void afficheSommets();
    void afficheArcs();
    void afficheListArcEntrantDansSommet(CSommet &sommet);
    void afficheListArcSortantDuSommet(CSommet &sommet);
    CPoint3f extent[2];
    void updateExtent(const CPoint3f&);
    CPoint3f getExtentUpperRight();
    CPoint3f getExtentLowerLeft();
    
};

#endif /* CGRAPHE_H_ */