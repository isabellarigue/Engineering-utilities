#include "affichage.h"
#include "tris_def.h"
#include "utils.h"
#include "tri.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string nomLire = "allumettes_donnees.txt";
  string nomEcrire = "allumettes_ecrites.txt";
  string nomFichier = "allumettes_aleatoires.txt";

  VectAllumettes vecAllu, vecGen;
  vecAllu = lireAllumettes(nomLire);
  //vecAllu = tri_insertion(40, vecAllu);
  //vecAllu = tri_abulles(vecAllu, 40);

  generationAleatoire(vecGen, nomFichier, 100);
  //init();
  vecGen = lireAllumettes(nomFichier);
  //affiche(vecGen);
  //finish();

  vecGen = tri_abulles(vecGen, 100);
  cout << "Fin" <<endl;
  /*
  Tri par insertion
  Avec 100: 8.31s
  Avec 1000: 8.93s
  Avec 10000:10.4s
  Avec 100000: 25.94s

  Tri par bulle
  Avec 100: 12s
  Avec 1000: 8.93s
  Avec 10000:10.4s
  Avec 100000: 25.94s
  */
  
  
  return 0;
}