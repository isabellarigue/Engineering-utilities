#ifndef UTILS_H
#define UTILS_H

#include "tris_def.h"
#include <fstream>
#include <iostream> //pour cout et cin
#include <string>

using namespace std;

VectAllumettes lireAllumettes(string nomFichier);

void ecrireFichier(VectAllumettes vector, string nomFichier);

void generationAleatoire(VectAllumettes vector, string nomFichier, int nbAllumettes);

#endif