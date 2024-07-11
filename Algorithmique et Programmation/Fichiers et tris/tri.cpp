#include "tris_def.h"
#include <iostream> //pour cout et cin
#include <string>
#include "affichage.h"

using namespace std;

// insere l’element d’indice i a l’indice j, avec j ≤ i 
VectAllumettes inserer(VectAllumettes allumettes, int i, int j) {
  Allumette tmp = allumettes[i];

  for(int k=i; k>=j ; k--) {
    allumettes[k] = allumettes[k-1];
    
  }
  allumettes[j] = tmp;

  return allumettes;
}

VectAllumettes tri_insertion(int nbAllumettes, VectAllumettes allumettes) {
  int i, j;
  //init();
  for(i=0; i<nbAllumettes-1; i++) {
    //affiche(allumettes);
    j = 0;
    while( j<i && (allumettes[j].taille <= allumettes[i].taille) ) {
      j++;
    }
    allumettes = inserer(allumettes, i, j);
  }
  //finish();
  return allumettes;
}

VectAllumettes permuter(VectAllumettes allumettes, int i, int j) {
  Allumette tmp = allumettes[i];
  
  allumettes[i] = allumettes[j];
  allumettes[j] = tmp;
  
  return allumettes;
}

VectAllumettes tri_bulles(VectAllumettes allumettes, int nbAllumettes){
  bool aucunEchange = false;
  init();

  for(int j = nbAllumettes; j > 0; j--){
    for (int i=0; i < j; i++){
        affiche(allumettes);
        if (allumettes[i].taille > allumettes[i+1].taille && allumettes[i].couleur > allumettes[i+1].couleur){
          allumettes = permuter(allumettes, i, i+1);
        }
      }
  }

  finish();
  return allumettes;
  
}

VectAllumettes tri_abulles(VectAllumettes allumettes, int nbAllumettes){
  bool aucunEchange = false;
  //init();

  while(!aucunEchange){
    aucunEchange = true;
    for (int i=0; i < nbAllumettes-1; i++){
        //affiche(allumettes);
        if (allumettes[i].taille > allumettes[i+1].taille){
          allumettes = permuter(allumettes, i, i+1);
          aucunEchange = false;
        }
    }
  }

  //finish();
  return allumettes;

}