#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "constantes.h"
#include "affichage.h"
#include "monde.h"
#include "fourmi.h"
#include "proba.h"

using namespace std;

int main(){
    int retour;
    t_monde monde;
    string fichier = "monde2.dat";
    vector<t_fourmi> formigas;

    monde = LireEnvironnement(fichier);

    retour= InitAffichage(monde.L, monde.H);

    for(int k = 0; k < 2; k++) {
        t_fourmi formiga;
        formiga.x = nalea(monde.L);
        formiga.y = nalea(monde.H);
        formiga.mode = 1;
        formiga.direction = 0; //nalea(8)
        formigas.push_back(formiga);
    }

    while(retour == 1){
        for(int i = 0; i < formigas.size(); i++){
            formigas[i] = DeplaceFourmi(formigas[i], monde);
            MiseAJourFourmi(formigas[i].x, formigas[i].y, formigas[i].mode);
            if(positionNourriture(formigas[i].x, formigas[i].y, monde)) {
                formigas[i].mode = 0;
            }
            if(arriveFourmiliere(formigas[i].x, formigas[i].y, monde)) {
                formigas[i].mode = 1; //ela chegou no formigueiro e vai voltar na busca de comida
                monde.mat[monde.Fy][monde.Fx] += 1;
            }
        }

        MiseAJourEnvironnement(monde);
        retour = Affichage();
    }

    return 0;
}