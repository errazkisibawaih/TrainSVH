//
//  main.cpp
//  TrainSVH
//
//  Created by Sibawaih Er-razki on 15/07/1437 AH.
//  Copyright © 1437 AH Sibawaih Er-razki. All rights reserved.
//

#include <iostream>

//============================================================================
// Name        : main.cpp
// Author      : Sibawaih
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "CDonneesGraphe.hpp"
#include "CGraphe.hpp"
#include "CSommet.hpp"
#include "drawrails.hpp"
#include "train.hpp"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

using namespace std;



train oncf;


int w=glutGet(GLUT_WINDOW_WIDTH) ;
int h=glutGet(GLUT_WINDOW_HEIGHT) ;

GLfloat White[]={1.,1.,1.};
GLfloat Black[]={0.,0.,0.};
GLfloat Red[]={1.,0.,0.};
GLfloat Green[]={0.,1.,0.};
GLfloat Blue[]={0.,0.,1.};
GLfloat Magenta[]={1.,0.,1.};
GLfloat Cyan[]={0.,1.,1.};
GLfloat Yellow[]={1.,1.,0.};

float xcam = 10;

float ycam = -13;


double distcam = 15;

double xcentre=14;

double ycentre=8;

double zcentre=0;

static int slices = 16;

static int stacks = 16;

/*
void traindessin(GLUquadricObj * quad, CPoint3f tete){
    int elev=1;
    glPushMatrix();
    glTranslated(tete.X,tete.Y,tete.Z+elev);
    glRotatef(0,0,0,1); //rotation pour suivre le graphe dans le plan
    glRotatef(0,1,1,0);
    glColor3d(1,0,1);
    glutSolidCube(1);
    glPopMatrix();
    

    
}

class train {
    public :
        CArc ArcActuel;			//arc sur lequel se déplace le train
        double Vitesse;			    //vitesse de déplacement
        CPoint3f Coord;			//position courante
        int PointAnnexeP;			//indice du prochain point annexe à atteindre
        CArc ArcProchain;
        train(CArc,double,CPoint3f,int,CArc);
    
};

train::train(CArc ArcActuel,double Vitesse,CPoint3f Coord, int PointAnnexeP,CArc ArcProchain )

{
    this->ArcActuel=ArcActuel;
    this->Vitesse=Vitesse;
    this->Coord=Coord;
    this->PointAnnexeP=PointAnnexeP;
    this->ArcProchain=ArcProchain;
}

*/

void defineWindow(const string & title)
{
    
    GLsizei ScreenWidth , ScreenHeight ;
    ScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
    ScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition(ScreenWidth, ScreenHeight);
    glutInitWindowSize(ScreenWidth, ScreenHeight );
    glutCreateWindow(title.c_str());
    glClearColor(0.,0.,0.,1.);

    
}
void initialize(const string & title)
{
    glutInitDisplayMode(GLUT_RGB);
    
    cout << "initialise" <<endl;
    
    
    
    defineWindow(title);
    
    glEnable(GL_DEPTH);
    glEnable(GL_DOUBLE);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING) ;
    
    int WindowWidth=glutGet(GLUT_WINDOW_WIDTH) ;
    int WindowHeight=glutGet(GLUT_WINDOW_HEIGHT) ;
    
    
    
    
    
int Ratio=(GLfloat)WindowWidth/WindowHeight;
    
    glMatrixMode( GL_PROJECTION );
    
    glLoadIdentity();
    
    //gluPerspective(70,Ratio,15,100);
    gluPerspective(90,Ratio,1,100);

    
    glMatrixMode( GL_MODELVIEW );
    
    glLoadIdentity();
    
    glPointSize(4);
    
    glLineWidth(2);
    
    
    

}

// Creation Arbre

static void Arbre( GLUquadricObj * quad,float X, float Y, float Z)

{
    
    glPushMatrix();
    
    glColor3d(0.6,0.2,0.0);
    
    glTranslated(X, Y, Z);
    
    glRotatef(0 ,-0.8, 1, 0);
    
    gluCylinder(quad, 0.2, 0.2, 2.6, 105, 1);
    
    glColor3d(0.2,0.6,0.0);
    
    glTranslated(0, 0, 3);
    
    glRotatef(180 ,0, 1, 0);
    
    glutSolidSphere(1,slices,stacks);
    
    glPopMatrix();
    
}


void pont (){
    
    
    
    GLfloat Grey[]={0.5,0.5,0.5};
    
    GLfloat Yellow[]={1.,1.,0.};
    
    
    
    float x1 = 10.0;
    
    float x2 = 11.0;
    
    float x3 = 13.0;
    
    float x4 = 14.0;
    
    float x5 = 9.5;
    
    float x6 = 14.5;
    
    float y1 = 2.5;
    
    float y2 = 3.5;
    
    float z1 = 2.0;
    
    float z2 = 2.4;
    
    
    
    float S1 [] = {x1,y1,0.0};
    
    float S2 [] = {x1,y2,0.0};
    
    float S3 [] = {x2,y1,z1};
    
    float S4 [] = {x2,y2,z1};
    
    float S5 [] = {x3,y1,z1};
    
    float S6 [] = {x3,y2,z1};
    
    float S7 [] = {x4,y1,0.0};
    
    float S8 [] = {x4,y2,0.0};
    
    
    
    float B1 [] = {x5,y1,0.0};
    
    float B2 [] = {x5,y2,0.0};
    
    float B3 [] = {x2,y1,z2};
    
    float B4 [] = {x2,y2,z2};
    
    float B5 [] = {x3,y1,z2};
    
    float B6 [] = {x3,y2,z2};
    
    float B7 [] = {x6,y1,0.0};
    
    float B8 [] = {x6,y2,0.0};
    
    
    
    // SOL
    
    glPushMatrix();
    
    glColor3fv(Green);
    
    glBegin(GL_QUADS);
    
    glVertex3fv(S1);
    
    glVertex3fv(S2);
    
    glVertex3fv(S4);
    
    glVertex3fv(S3);
    
    
    
    glVertex3fv(S3);
    
    glVertex3fv(S4);
    
    glVertex3fv(S6);
    
    glVertex3fv(S5);
    
    
    
    glVertex3fv(S5);
    
    glVertex3fv(S6);
    
    glVertex3fv(S8);
    
    glVertex3fv(S7);
    
    glEnd();
    
    glPopMatrix();
    
    
    
    // Barriere
    
    glPushMatrix();
    
    glColor3fv(Yellow);
    
    // Barriere Sud
    
    glBegin(GL_QUADS);
    
    glVertex3fv(S1);
    
    glVertex3fv(B1);
    
    glVertex3fv(B3);
    
    glVertex3fv(S3);
    
    
    
    glVertex3fv(S3);
    
    glVertex3fv(B3);
    
    glVertex3fv(B5);
    
    glVertex3fv(S5);
    
    
    
    glVertex3fv(S5);
    
    glVertex3fv(B5);
    
    glVertex3fv(B7);
    
    glVertex3fv(S7);
    
    glEnd();
    
    
    
    // Barriere Nord
    
    glBegin(GL_QUADS);
    
    glVertex3fv(S2);
    
    glVertex3fv(B2);
    
    glVertex3fv(B4);
    
    glVertex3fv(S4);
    
    
    
    glVertex3fv(S4);
    
    glVertex3fv(B4);
    
    glVertex3fv(B6);
    
    glVertex3fv(S6);
    
    
    
    glVertex3fv(S6);
    
    glVertex3fv(B6);
    
    glVertex3fv(B8);
    
    glVertex3fv(S8);
    
    glEnd();
    
    
    
    glPopMatrix();
    
}



static void Tunnel( GLUquadricObj * quad,float X, float Y, float Z, float Rotx, float Roty, float Rotz)

{
    
    GLfloat Gris[]={0.3,0.3,0.3};
    
    glPushMatrix();
    
    glColor3fv(Gris);
    
    glTranslated(X,Y,Z);
    
    glRotatef(Rotx ,Roty, Rotz, 0);
    
    gluCylinder(quad, 1.2, 1.2, 6, 35, 1);
    
    glPopMatrix();
    
}


train InitialisTrain(int sommet)

{
    
    // construction des tables du graphe
    CDonneesGraphe gdata("/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SIF.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/PAXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/AXYZ.TXT");
    // affichage des donnees
    gdata.afficheDonnees();
    // Constrcuction de la base de donnees orientee objet du graphe
    CGraphe graphe(gdata);
    
    //initialisation des trains
    train lgv;
    lgv.Vitesse = 0.05;
    CSommet Sommet_depart=graphe.list_sommet.at(sommet);
    int idArcAlea=rand()%graphe.getListArcSortantDuSommet(Sommet_depart).size();
    lgv.ArcActuel = graphe.getListArcSortantDuSommet(Sommet_depart).at(idArcAlea);
    int Id_somme_depart =lgv.ArcActuel.id_sommet_ini;
    lgv.Coord=(CPoint3f)graphe.list_sommet.at(Id_somme_depart);
    lgv.PointAnnexeP=0;
    return lgv;
    
}



void DrawTrain(train oncf){
    static double elev = 0.33;
    glPushMatrix();
    glTranslated(oncf.Coord.X,oncf.Coord.Y,oncf.Coord.Z+elev);
    glRotatef(0,0,0,1); //rotation pour suivre le graphe dans le plan
    glRotatef(0,1,1,0);
    glColor3d(1,0,1);
    glutSolidCube(1);
    glPopMatrix();
    glutSwapBuffers();
    }


static void lune(float X, float Y, float Z)

{
    
    glPushMatrix();
    glColor3d(1.,1.,1.);
    glTranslated(X, Y, Z);
    glutSolidSphere(1.5,slices,stacks);
    glPopMatrix();
    
}



/*
void trainchemin() {
    
    static GLUquadricObj * quad;
    int t=0;
    cout<< "Hello \n" << __FILE__ << endl;
    // construction des tables du graphe
    CDonneesGraphe gdata("/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SIF.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/PAXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/AXYZ.TXT");
    // affichage des donnees
    gdata.afficheDonnees();
    // Constrcuction de la base de donnees orientee objet du graphe
    CGraphe graphe(gdata);
    cout<<"Generation aléatoire de sommet début su train"<<endl;
    int Srand = rand() % gdata.NS;
    //vector<CArc> listArcEntrant = graphe.getListArcEntrantDansSommet(Sinit);
    CSommet Sinit = graphe.list_sommet.at(Srand);
    cout<<Sinit.toString()<<endl;
    CSommet loop =Sinit;
    cout<<"Bisslimlah"<<endl;
    while ( t==0) {
        vector<CArc> listArcSortant = graphe.getListArcSortantDuSommet(Sinit);
        cout << "le nombre de sommet "<<gdata.NS<<endl;
        int nbsortant = listArcSortant.size();
        cout<<nbsortant<<endl;
        int sch=rand() % nbsortant;
        cout<<sch<<endl;
        CArc arc = listArcSortant.at(sch);
        cout<<"repectivement id arc id sommet init et sommet final"<<endl;
        cout<<arc.id_arc<<endl;
        cout<<arc.id_sommet_ini<<endl;
        cout<<arc.id_sommet_fin<<endl;
        CSommet si = graphe.list_sommet.at(arc.id_sommet_ini);
        //train(quad,si);
        cout<<"les coordonnees du points init "<<" X: "<< si.X<<" Y: "<< si.Y<<" Z: "<< si.Z<<endl;
        vector<CPointAnnexe> pa=graphe.getListPointAnnexeArc(arc);
        int m=pa.size();
        for( int j=0 ; j<m ; ++j) {
            cout<<" X: "<< pa[j].X <<" Y: " << pa[j].Y <<" Z: "<< pa[j].Z <<endl;
            //train(quad,pa[j]);
        }
        CSommet sf = graphe.list_sommet.at(arc.id_sommet_fin);
        cout<<"les coordonnees du points final "<<" X: "<< sf.X<<" Y: "<< sf.Y<<" Z: "<< sf.Z<<endl;
        //train(quad,sf);
        glFlush();
        Sinit=sf;
        if(loop.X==sf.X and loop.Y==sf.Y and loop.Z==sf.Z ) { t=1 ; }
    }
    

    cout<<"nombre arc "<<graphe.nb_arc<<endl;
    CSommet Si = sf;
    cout<<Si.toString()<<endl;
    vector<CArc> test = graphe.getListArcSortantDuSommet(Si);
    nbsortant = test.size();
    cout<<nbsortant<<endl;
    int a=rand();
    cout<<"random"<<a<<endl;
    sch=a % nbsortant;
    cout<<sch<<endl;
    arc = test.at(sch);
    */



void DrawArcs() {
    
    cout<< "Hello \n" << __FILE__ << endl;
    // construction des tables du graphe
    CDonneesGraphe gdata("/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SIF.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/PAXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/AXYZ.TXT");
    // affichage des donnees
    gdata.afficheDonnees();
    // Constrcuction de la base de donnees orientee objet du graphe
    CGraphe graphe(gdata);
    // Preparation du generateur de nombre aleatoire
    int NA=graphe.nb_arc;
    //Création des arcs
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    vector<CArc> arcs=graphe.list_arc ;
    for(int i=0 ; i<NA ; i++) {
        glColor3fv(Green);
        glPushMatrix();
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
    glPopMatrix();
    
}

void DrawArea()
{
    
    
    cout<< "Hello \n" << __FILE__ << endl;
    // construction des tables du graphe
    CDonneesGraphe gdata("/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SIF.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/PAXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/AXYZ.TXT");
    // affichage des donnees
    gdata.afficheDonnees();
    // Constrcuction de la base de donnees orientee objet du graphe
    CGraphe graphe(gdata);
    // Preparation du generateur de nombre aleatoire
    int NA=graphe.nb_arc;
    GLfloat GREEN[] = {0.,1.,0.,1.};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* un affichage commence toujours par cette fonction */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xcam,ycam,distcam,xcentre,ycentre,zcentre,0,1,0);
    
    // Dessin des Arcs
    DrawArcs();
    
    //Tunnel
    static GLUquadricObj * quad;
    quad = gluNewQuadric();
    CPoint3f p1 = gdata.AXYZ.at(gdata.PAXYZ.at(2).colonne_1-1);
    Tunnel(quad, p1.X, p1.Y, p1.Z, 90, 1, 0.5);
    
    //Création su pont
    pont();
    
    CPoint3f p2 = gdata.AXYZ.at(gdata.PAXYZ.at(4).colonne_1-3);
    
    CPoint3f p3 = gdata.AXYZ.at(gdata.PAXYZ.at(6).colonne_1-1);
    
    float X2=p2.X;
    float  Y2=p2.Y;
    float Z2=p2.Z;
    float X3=p3.X;
    float Y3=p3.Y;
    float Z3=p3.Z;

    
    //Création des arbres
    Arbre(quad, p1.X-5,p1.Y-4,p1.Z);
    Arbre(quad, p1.X-3,p1.Y-2,p1.Z);
    Arbre(quad, p1.X-8,p1.Y-3,p1.Z);
    Arbre(quad, p1.X-11,p1.Y-5,p1.Z);
    Arbre(quad, X2-3,Y2-6,Z2);
    Arbre(quad, X2-6,Y2-6,Z2);
    Arbre(quad, X2-4,Y2-6,Z2);
    Arbre(quad, X3-4,Y3-4,Z3);
    Arbre(quad, X3-5,Y3-3,Z3);
    Arbre(quad, X3-6,Y3-5,Z3);
    Arbre(quad, X3+6,Y3-15,Z3);
    Arbre(quad, X3+7,Y3-13,Z3);
    Arbre(quad, X3+5,Y3-11,Z3);
    Arbre(quad, X3+8,Y3-2,Z3);
    Arbre(quad, X3+9,Y3-3,Z3);
    Arbre(quad, X3+7,Y3-1,Z3);
    Arbre(quad, X3+4,Y3-2,Z3);
    Arbre(quad, X3+5,Y3-3,Z3);
    Arbre(quad, X3+6,Y3-4,Z3);
    Arbre(quad, X3+7,Y3-5,Z3);
    
    //Création de la lune
    lune(0, 20, 8);
    
    //Création des trains
    
    double dx;
    double dy;
    double dz;
    DrawTrain(oncf);
    int t=0;

    
    //vector<CArc> listArcEntrant = graphe.getListArcEntrantDansSommet(Sinit);
    CSommet Sinit = graphe.list_sommet.at(0);
    cout<<Sinit.toString()<<endl;
    CSommet loop =Sinit;
    cout<<"Bisslimlah"<<endl;
    while ( t==0) {
        vector<CArc> listArcSortant = graphe.getListArcSortantDuSommet(Sinit);
        cout << "le nombre de sommet "<<gdata.NS<<endl;
        int nbsortant = listArcSortant.size();
        cout<<nbsortant<<endl;
        int sch=rand() % nbsortant;
        cout<<sch<<endl;
        CArc arc = listArcSortant.at(sch);
        cout<<"repectivement id arc id sommet init et sommet final"<<endl;
        cout<<arc.id_arc<<endl;
        cout<<arc.id_sommet_ini<<endl;
        cout<<arc.id_sommet_fin<<endl;
        CSommet si = graphe.list_sommet.at(arc.id_sommet_ini);
        //glutSwapBuffers();
        oncf.Coord.X=si.X;
        oncf.Coord.Y=si.Y;
        oncf.Coord.Z=si.Z;
        oncf.ArcActuel=arc;
        //DrawTrain(oncf);
        cout<<"les coordonnees du points init "<<" X: "<< si.X<<" Y: "<< si.Y<<" Z: "<< si.Z<<endl;
        vector<CPointAnnexe> pa=graphe.getListPointAnnexeArc(arc);
        oncf.PointAnnexeP=pa[0].id_point_annex;
        int m=pa.size();
        for( int j=0 ; j<m ; ++j) {
            cout<<" X: "<< pa[j].X <<" Y: " << pa[j].Y <<" Z: "<< pa[j].Z <<endl;
            if(j!=m-1) {
                oncf.PointAnnexeP=pa[j].id_point_annex;
                oncf.Coord.X=pa[j].X;
                oncf.Coord.Y=pa[j].Y;
                oncf.Coord.Z=pa[j].Z;
                //DrawTrain(oncf);
            }
            else {
                oncf.PointAnnexeP=0;
            }
            
        }
        CSommet sf = graphe.list_sommet.at(arc.id_sommet_fin);
        cout<<"les coordonnees du points final "<<" X: "<< sf.X<<" Y: "<< sf.Y<<" Z: "<< sf.Z<<endl;
        oncf.Coord.X=sf.X;
        oncf.Coord.Y=sf.Y;
        oncf.Coord.Z=sf.Z;
        //DrawTrain(oncf);
        
        Sinit=sf;
        if(loop.X==sf.X and loop.Y==sf.Y and loop.Z==sf.Z ) { t=1 ; }
    }
    
    
    
    //trainchemin();
    glFlush();
}

int main(int argc, char *argv[]) {
    
    cout<< "Hello \n" << __FILE__ << endl;
    // construction des tables du graphe
    CDonneesGraphe gdata("/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/SIF.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/PAXYZ.TXT",
                         "/Users/sibawaiher-razki/Desktop/Etude/Projet/ProjetOpenGL/TrainSVH/TrainSVH/data/AXYZ.TXT");
    // affichage des donnees
    gdata.afficheDonnees();
    // Constrcuction de la base de donnees orientee objet du graphe
    CGraphe graphe(gdata);
    // Preparation du generateur de nombre aleatoire
    srand((unsigned)time(NULL));
    // Tirage d'un nombre aleatoire entre 0 et NS (nombre de sommet)
    int iSommet = rand() % gdata.NS;
    cout<<iSommet<<endl;
    // Recuperation du sommet
    CSommet sommet = graphe.list_sommet.at(iSommet);
    cout<<"je suis la "<<endl;
    cout<<sommet.toString()<<endl;
    cout<<"fin"<<endl;
    // Recuperation arcs entrants
    vector<CArc> list_arc_entrant = graphe.getListArcEntrantDansSommet(sommet);
    cout<< "c'est uou ca ?"<<endl;
    int nb_arc_entrant = list_arc_entrant.size();
    for (int i = 0; i < nb_arc_entrant; ++i) {
        CArc arc = list_arc_entrant.at(i);
        cout<<arc.toString()<<endl;
    }
    
    
    graphe.afficheSommets();
    graphe.afficheArcs();
    graphe.buildExtent();
    cout<<graphe.getExtentLowerLeft().toString()<<endl;
    cout<<graphe.getExtentUpperRight().toString()<<endl;
    
    cout<<"Affichage de tout le graphe et ses points annexes"<<endl;
    
    int n=gdata.NA;
    vector<CArc> arcs=graphe.list_arc ;
    for(int i=0 ; i<n ; i++) {
        cout<<"id de l'arc : "<< arcs[i].id_arc << " sommet Initial : " << arcs[i].id_sommet_ini<<" sommet final : " << arcs[i].id_sommet_fin<<endl;
        CSommet si = graphe.list_sommet.at(arcs[i].id_sommet_ini);
        CSommet sf = graphe.list_sommet.at(arcs[i].id_sommet_fin);
        cout<<" Cordonnee du points Initial"<<" X: "<< si.X<<" Y: "<< si.Y<<" Z: "<< si.Z<<endl;
        cout<<" Cordonnee du point Final"<<" X: "<< sf.X<<" Y: "<< sf.Y<<" Z: "<< sf.Z<<endl;
        vector<CPointAnnexe> pa=graphe.getListPointAnnexeArc(arcs[i]);
        int m=pa.size();
        for( int j=0 ; j<m ; ++j) {
            cout<<" X: "<< pa[j].X <<" Y: " << pa[j].Y <<" Z: "<< pa[j].Z <<endl;
        }
    }
    /*
    cout<<"Generation aléatoire de sommet début su train"<<endl;
    int Srand = rand() % gdata.NS;
    //vector<CArc> listArcEntrant = graphe.getListArcEntrantDansSommet(Sinit);
    CSommet Sinit = graphe.list_sommet.at(Srand);
    cout<<Sinit.toString()<<endl;
    vector<CArc> listArcSortant = graphe.getListArcSortantDuSommet(Sinit);
    cout << "le nombre de sommet "<<gdata.NS<<endl;
    int nbsortant = listArcSortant.size();
    cout<<nbsortant<<endl;
    int sch=rand() % nbsortant;
    cout<<sch<<endl;
    CArc arc = listArcSortant.at(sch);
    cout<<"repectivement id arc id sommet init et sommet final"<<endl;
    cout<<arc.id_arc<<endl;
    cout<<arc.id_sommet_ini<<endl;
    cout<<arc.id_sommet_fin<<endl;
    CSommet si = graphe.list_sommet.at(arc.id_sommet_ini);
    cout<<"les coordonnees du points init "<<" X: "<< si.X<<" Y: "<< si.Y<<" Z: "<< si.Z<<endl;
    vector<CPointAnnexe> pa=graphe.getListPointAnnexeArc(arc);
    int m=pa.size();
    for( int j=0 ; j<m ; ++j) {
        cout<<" X: "<< pa[j].X <<" Y: " << pa[j].Y <<" Z: "<< pa[j].Z <<endl;
    }
    CSommet sf = graphe.list_sommet.at(arc.id_sommet_fin);
    cout<<"les coordonnees du points final "<<" X: "<< sf.X<<" Y: "<< sf.Y<<" Z: "<< sf.Z<<endl;
    cout<<"nombre arc "<<graphe.nb_arc<<endl;
    CSommet Si = sf;
    cout<<Si.toString()<<endl;
    vector<CArc> test = graphe.getListArcSortantDuSommet(Si);
    nbsortant = test.size();
    cout<<nbsortant<<endl;
    int a=rand();
    cout<<"random"<<a<<endl;
    sch=a % nbsortant;
    cout<<sch<<endl;
    arc = test.at(sch);
    */
    
    oncf=InitialisTrain(0);
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    initialize(argv[0]);
    glutDisplayFunc(DrawArea);
    glutIdleFunc(DrawArea);
    //glutDisplayFunc(DrawArea);
    
    //glutIdleFunc(drawr);
    //glTranslatef( 3., 0.0, 0.0 );
    //glRotatef(-60.0,0.,0.,1.);
    glutMainLoop();
    return EXIT_SUCCESS;

}
