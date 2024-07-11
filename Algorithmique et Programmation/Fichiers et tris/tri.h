#ifndef TRI_H
#define TRI_H

#include "tris_def.h"
#include <iostream> //pour cout et cin
#include <string>
#include "affichage.h"

using namespace std;

VectAllumettes inserer(VectAllumettes allumettes, int i, int j);
VectAllumettes permuter(VectAllumettes allumettes, int i, int j);

VectAllumettes tri_insertion(int nbAllumettes, VectAllumettes allumettes);
VectAllumettes tri_bulles(VectAllumettes allumettes, int nbAllumettes);
VectAllumettes tri_abulles(VectAllumettes allumettes, int nbAllumettes);

#endif