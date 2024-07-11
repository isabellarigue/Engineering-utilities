#ifndef FOURMI_H
#define FOURMI_H

#include "proba.h"
#include "monde.h"

using namespace std;

struct t_fourmi {
    int x, y; //position
    int mode; //0 : en retournant à la fourmillière
//              1 : en recherche de nourriture
    int direction;
};

void DeplaceFourmi1(t_fourmi& fourmi);
int modulo8(int x);
int positionNourriture(int x, int y, t_monde monde);
int PositionPossible(int x, int y, t_monde monde);
int DirFourmiliere(int x, int y, int Fx, int Fy);
t_fourmi DeplaceFourmi(t_fourmi fourmi, t_monde environnement);
int arriveFourmiliere(int x, int y, t_monde monde);

#endif