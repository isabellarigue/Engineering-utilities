#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

#include "type_def.h"
#include "utilitaire_generation.h"

/**
initTab : création d'une personne à partir de valeurs connues
*/
void initTab(const string &nomFichier, vector<string> &tab) {
  int i;
  int nb;

  ifstream input(nomFichier);
  if (input.fail())
    cerr << "pb lecture fichier" << endl;
  else {
    input >> nb;
    //	cout<<nb<<endl;
    tab.resize(nb);

    for (i = 0; i < nb; i++) {
      input >> tab[i];
      //        cout<<tab[i]<<endl;
    }
  }
  input.close();
}

/**
creerPersonne : création d'une personne à partir de valeurs connues
*/
personne creerPersonne(const string &nom, const string &prenom,
                       const string &secu) {
  personne result;

  result.nom = nom;
  result.prenom = prenom;
  result.numss = secu;

  return result;
}

/**
genererPersonne : génération des valeurs d'une personne
*/
personne genererPersonne(const string *listNom, const string *listPrenom,
                         int nbNom, int nbPrenom) {
  char sexe[2], annee[3], moisNaiss[3], depart[3], commune[4], etatCiv[4];
  sprintf(sexe, "%d", rand() % 2 + 1);
  sprintf(annee, "%02d", rand() % 98 + 1);
  sprintf(moisNaiss, "%02d", rand() % 12 + 1);
  sprintf(depart, "%02d", rand() % 98 + 1);
  sprintf(commune, "%03d", rand() % 998 + 1);
  sprintf(etatCiv, "%03d", rand() % 998 + 1);

  // cout<<annee<<" "<<moisNaiss<<" "<<depart<<" "<<commune<<" "<<etatCiv<<endl;

  string num = string(sexe, 1) + string(annee, 2) + string(moisNaiss, 2) +
               string(depart, 2) + string(commune, 3) + string(etatCiv, 3);

  // cout<<num<<endl;

  return creerPersonne(listNom[rand() % nbNom], listPrenom[rand() % nbPrenom],
                       num);
}

/**
genererPersonne : génération des valeurs d'une personne avec vector
*/
personne genererPersonne(const vector<string> &listNom,
                         const vector<string> &listPrenom) {
  return genererPersonne(listNom.data(), listPrenom.data(), listNom.size(),
                         listPrenom.size());
}

/**
genererRepertoire : génération de nbPers personnes
*/
void genererRepertoire(const string &nomFichier, const vector<string> &listNom,
                       const vector<string> &listPrenom, int nbPers) {
  int i;
  personne tmp;

  ofstream output(nomFichier);
  if (output.fail())
    cerr << "pb ecriture fichier" << endl;
  else {
    output << nbPers << endl; // en option pour faciliter la lecture
    for (i = 0; i < nbPers; i++) {
      tmp = genererPersonne(listNom, listPrenom);
      output << tmp.nom << " " << tmp.prenom << " " << tmp.numss << endl;
    }
  }
}
