#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#include "type_def.h"
#include "utilitaires.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ajouterTableau(personne personne, vectPersonne &personnes, int i = 0);
elementListe *ajouterListe(personne personne, elementListe *element);
noeud *ajouterArbre(personne personne, noeud* racine);

vectPersonne lectureRepertoireTableau(string nomFichier);
elementListe* lectureRepertoireListe(string nomFichier);
noeud* lectureRepertoireArbre(string nomFichier);

void afficherTableau(vectPersonne personnes, int i = 0);
void afficherListe (elementListe *element);
void afficherArbre(noeud* racine);

int rechercherTableau(personne personneAdd, vectPersonne personnes, int indice = 0);
elementListe* rechercherListe(personne personne, elementListe *element);
noeud *rechercherArbre(personne personne, noeud* racine);

void supprimerTableau(personne personne,vectPersonne personnes);
elementListe* supprimerListe(personne personne, elementListe* element);
void supprimerSucesseur(noeud* racine);
noeud* supprimerArbre(personne personne, noeud* racine);

#endif