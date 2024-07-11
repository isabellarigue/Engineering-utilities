#include "type_def.h"
#include <string>

using namespace std;

bool egalitePersonne(personne personne1, personne personne2){
  if (personne1.nom == personne2.nom &&
      personne1.prenom == personne2.prenom &&
      personne1.numss == personne2.numss)
      return true;

  return false;
}

bool inferieurPersonne(personne personne1, personne personne2){
  if (personne1.nom > personne2.nom)
    return true;
  else if (personne1.prenom > personne2.prenom && personne1.nom == personne2.nom)
    return true;
  else if (personne1.numss > personne2.numss && personne1.prenom == personne2.prenom && personne1.nom == personne2.nom)
    return true;

  return false;
}