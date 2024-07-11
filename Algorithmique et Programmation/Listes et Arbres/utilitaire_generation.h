#ifndef UTILITAIRE_GENERATION_H_INCLUDED
#define UTILITAIRE_GENERATION_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

#include "type_def.h"

void initTab(const string & nomFichier, vector<string> & tab);

personne creerPersonne(const string & nom, const string & prenom,const string & secu);
                          
personne genererPersonne(const string* listNom, const string* listPrenom, int nbNom, int nbPrenom);

personne genererPersonne(const vector<string>& listNom, const vector<string>& listPrenom);

void genererRepertoire(const string & nomFichier,const vector<string>& listNom, const vector<string>& listPrenom, int nbPers);

#endif // UTILITAIRES_H_INCLUDED
