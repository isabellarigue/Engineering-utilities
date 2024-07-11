#include "type_def.h"
#include "utilitaires.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
/*

}*/

using namespace std;

void ajouterTableau(personne personne, vectPersonne &personnes,
                    int i = 0) { // recursif
  if (personnes[i].nom == "") {
    personnes.push_back(personne);
    return;
  }

  if (egalitePersonne(personne, personnes[i])) {
    return;
  }

  if (inferieurPersonne(personne, personnes[i])) {
    personnes.resize(personnes.size() + 1);

    for (int j = personnes.size() - 1; j > i; j--) {
      personnes[j] = personnes[j - 1];
    }
    personnes[i] = personne;

  } else {
    ajouterTableau(personne, personnes, i + 1);
  }
}

elementListe *ajouterListe(personne personne,
                           elementListe *element) { // recursif
  if (element == NULL) {
    elementListe *newPersonne;
    newPersonne->personne = personne;
    newPersonne->suivant = NULL;
    return newPersonne;
  } else {
    if (egalitePersonne(personne, element->personne))
      return element;
    if (inferieurPersonne(personne, element->personne))
      ajouterListe(personne, element->suivant);
    else {
      elementListe *newPersonne;
      newPersonne->personne = personne;
      newPersonne->suivant = element->suivant->suivant;
      element->suivant = newPersonne;
    }
  }
  return element;
}

noeud *ajouterArbre(personne personne, noeud* racine) {
  if (egalitePersonne(personne , racine->personne)){
    return racine;
  } else if (racine == NULL){
    noeud* racine;
    racine->personne = personne;
    racine->filsDroit = NULL;
    racine->filsGauche = NULL;
    return racine;
  } else {
    if (inferieurPersonne(racine->personne, personne)){
      racine->filsGauche = ajouterArbre(personne, racine->filsGauche);
    }
    else{
      racine->filsDroit = ajouterArbre(personne, racine->filsDroit);
    }
  }
  return racine;
}

vectPersonne lectureRepertoireTableau(string nomFichier) {
  ifstream inputFile;
  int nb;
  vectPersonne personnes;

  inputFile.open(nomFichier);

  inputFile >> nb;

  for (int i = 0; i < nb; i++) {
    personne tmp;

    inputFile >> tmp.nom;
    inputFile >> tmp.prenom;
    inputFile >> tmp.numss;
    ajouterTableau(tmp, personnes);
  }

  inputFile.close();

  return personnes;
}

elementListe* lectureRepertoireListe(string nomFichier){
  ifstream inputFile;
    int nb;
    elementListe* liste;

    inputFile.open(nomFichier);

    inputFile >> nb;

    for (int i = 0; i < nb; i++) {
      personne tmp;

      inputFile >> tmp.nom;
      inputFile >> tmp.prenom;
      inputFile >> tmp.numss;
      ajouterListe(tmp, liste);
    }

    inputFile.close();

    return liste;
  }

noeud* lectureRepertoireArbre(string nomFichier){
  ifstream inputFile;
  int nb;
  noeud* arbre;

  inputFile.open(nomFichier);

  inputFile >> nb;

  for (int i = 0; i < nb; i++) {
    personne tmp;

    inputFile >> tmp.nom;
    inputFile >> tmp.prenom;
    inputFile >> tmp.numss;
    ajouterArbre(tmp, arbre);
  }

  inputFile.close();

  return arbre;
}

void afficherTableau(vectPersonne personnes, int i = 0) { // recursif
  if (personnes[i].nom == "") {
    return;
  }
  cout << personnes[i].nom;
  cout << personnes[i].prenom;
  cout << personnes[i].numss;
  cout << endl;
  afficherTableau(personnes, i + 1);
}

void afficherListe (elementListe *element){
  cout << element->personne.nom;
  cout << element->personne.prenom;
  cout << element->personne.numss;
  cout << endl;
  afficherListe(element->suivant);
}

void afficherArbre(noeud* racine){
  afficherArbre(racine->filsGauche);
  cout << racine->personne.nom;
  cout << racine->personne.prenom;
  cout << racine->personne.numss;
  cout << endl; 
  afficherArbre(racine->filsDroit);
}

int rechercherTableau(personne personneAdd, vectPersonne personnes,
                      int indice = 0) { // recursif
  if (personnes[indice].nom == "") {
    return -1;
  } else {
    if (egalitePersonne(personneAdd, personnes[indice]))
      return indice;
    rechercherTableau(personneAdd, personnes, indice + 1);
  }
}

elementListe* rechercherListe(personne personne, elementListe *element){
  if(element == NULL){
    return NULL;
  }
  if(egalitePersonne(personne, element->personne)){
    return element;
  } else {
    rechercherListe(personne, element->suivant);
  }
  return NULL;
}

noeud *rechercherArbre(personne personne, noeud* racine){
  if (racine == NULL){
    return NULL;
  }
  if (egalitePersonne(personne, racine->personne)){
    return racine;
  }
  if ( inferieurPersonne(personne, racine->personne) ){ //recherche dans les rames droites
    rechercherArbre(personne, racine->filsDroit);
  } else {
    rechercherArbre(personne, racine->filsGauche);
  }
  return racine;
}

void supprimerTableau(personne personne,
                      vectPersonne personnes) { // non recursif
  int index;
  index = rechercherTableau(personne, personnes);

  int k = index;
  for (int j = index; j >= 0; j--){
    personnes[j] = personnes[k++];
  }
}

elementListe* supprimerListe(personne personne, elementListe* element){
  if (element == NULL){
    return NULL;
  } else if ((egalitePersonne(personne, element->personne))){
    return element->suivant;
  } else if (egalitePersonne(personne, element->suivant->personne)){
    element->suivant = element->suivant->suivant;
  } else {
    supprimerListe(personne, element->suivant);
  }
  return element;
}

void supprimerSucesseur(noeud* racine) {
  noeud* min = racine->filsDroit;
  noeud* pere = racine;
  while (min->filsGauche != NULL) {
    pere = min;
    min = min ->filsGauche;
  }
  if(pere->filsGauche == min)
    pere->filsGauche = min->filsDroit;
  else
    pere->filsDroit = min->filsDroit;
  
  racine->personne = min->personne;
}

noeud* supprimerArbre(personne personne, noeud* racine){
  if (racine == NULL){
    return NULL;
  }
  if (inferieurPersonne(racine->personne,personne)) 
    supprimerArbre(personne, racine->filsGauche);
  else if (inferieurPersonne(personne,racine->personne))
    supprimerArbre(personne, racine->filsDroit);
  else if(racine->filsGauche == NULL)
    return racine->filsDroit;
  else if(racine->filsDroit == NULL)
    return racine->filsGauche;
  else
    supprimerSucesseur(racine);
  return racine;
}