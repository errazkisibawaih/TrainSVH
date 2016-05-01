//
//  drawrails.cpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//
#include "CDonneesGraphe.hpp"
#include "CGraphe.hpp"
#include "CSommet.hpp"
//#include "drawrails.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


#include "drawrails.hpp"
using namespace std;

drawrails::drawrails(CGraphe graphe) : graphe(graphe)  {}

void  drawrails::defineWindow(const string & title)
{
    GLsizei screenWidht, screenHeight ;
    
    screenWidht= 1500;
    screenHeight= 1500;
    
    glutInitWindowPosition(screenWidht,screenHeight);
    glutInitWindowSize(screenWidht,screenWidht);
    glutInitWindowPosition(0,0);
    glutCreateWindow(title.c_str());
    
    glClearColor(0.,0.,0.,1.);
}
void drawrails::initialize(const string & title)
{
    glutInitDisplayMode(GLUT_RGBA);
    defineWindow(title);
    glOrtho(-10,10,-10,10,-10,10);
}



void drawrails::drawr()
{
    int NA=graphe.nb_arc;
    GLfloat GREEN[] = {0.,1.,0.,1.};
    
    vector<CArc> arcs=graphe.list_arc ;
    for(int i=0 ; i<NA ; i++) {
        glColor3fv(GREEN);
        CSommet si = graphe.list_sommet.at(arcs[i].id_sommet_ini);
        CSommet sf = graphe.list_sommet.at(arcs[i].id_sommet_fin);
        vector<CPointAnnexe> pa=graphe.getListPointAnnexeArc(arcs[i]);
        int m=pa.size();
        
        glBegin(GL_LINE_STRIP); {
            glVertex3f(si.X,si.Y,si.Z);
            for( int j=0 ; j<m ; ++j) {
                glVertex3f(pa[j].X,pa[j].Y,pa[j].Z);
            }
            glVertex3f(sf.X,sf.Y,sf.Z);
        }
        glEnd();
    
    }
    
    
    
    glFlush();
}

/*
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    initialize("Grille");
    glutDisplayFunc(drawgrille);
    glTranslatef( 3., 0.0, 0.0 );
    glRotatef(-60.0,0.,0.,1.);
    glutMainLoop();
    return EXIT_SUCCESS;
}
*/
