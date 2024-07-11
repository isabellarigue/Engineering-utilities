#include "tris_def.h"
#include <fstream>
#include <iostream> //pour cout et cin
#include <string>

using namespace std;

VectAllumettes lireAllumettes(string nomFichier) {
  ifstream inputFile;
  int qte;
  VectAllumettes vector;

  inputFile.open(nomFichier);
  inputFile >> qte;

  for (int i = 0; i < qte; i++) {
    Allumette tmp;

    inputFile >> tmp.couleur;
    inputFile >> tmp.taille;
    vector.push_back(tmp);
  }

  inputFile.close();

  return vector;
}

void ecrireFichier(VectAllumettes vector, string nomFichier) {
  ofstream outputFile;
  outputFile.open(nomFichier);
  outputFile << vector.size() << endl;
  for (int i = 0; i < vector.size(); i++) {
    outputFile << vector[i].couleur << " " << vector[i].taille << endl;
  }
  outputFile.close();
}

void generationAleatoire(VectAllumettes vector, string nomFichier, int nbAllumettes) {
  ofstream outputFile;
  Allumette a;
  int couleur, taille;

  //Generation des allumettes
  for (int i = 0; i < nbAllumettes; i++) {
  
    couleur = (rand() % 6);
    taille = 1+ (rand() % 20);

    a.couleur = couleur;
    a.taille = taille;

    vector.push_back(a);
  }

  ecrireFichier(vector, nomFichier);
}