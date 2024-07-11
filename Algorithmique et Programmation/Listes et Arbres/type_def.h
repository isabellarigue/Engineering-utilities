#ifndef TYPE_DEF_H
#define TYPE_DEF_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct personne {
  string nom;
  string prenom;
  string numss;
};

typedef vector<personne> vectPersonne;

struct elementListe {
  personne personne;
  elementListe *suivant;
};

struct noeud {
  personne personne;
  noeud *filsDroit;
  noeud *filsGauche;
};

#endif