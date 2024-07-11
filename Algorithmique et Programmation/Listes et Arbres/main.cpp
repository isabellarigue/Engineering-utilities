#include <iostream>
#include <string>
#include <vector>
#include "utilitaire_generation.h"
#include "repertoire.h"
#include "utilitaires.h"
#include "type_def.h"

int main() {
  vector<string> noms, prenoms;
  vectPersonne people;
  elementListe* personne;
  noeud* arbre;
  string nomFichier = "Repertoire.txt";
  
  /*
  initTab("Noms.txt", noms);
  initTab("Prenoms.txt", prenoms);
  genererRepertoire("Repertoire.txt", noms, prenoms, 10000);
 */

  people = lectureRepertoireTableau(nomFichier);
  //personne = lectureRepertoireListe(nomFichier);
  //arbre = lectureRepertoireArbre(nomFichier);

  afficherTableau(people);
  //afficherListe (personne);
  //afficherArbre(arbre);

  return 0;
}