#include "constantes.h"
#include <fstream>
#include <iostream> //pour cout et cin
#include <string>
#include <vector>

using namespace std;

t_monde LireEnvironnement(string nomFichier) {
    ifstream inputFile;
    int valeur;
    t_monde monde;
    vector<int> aux;

    inputFile.open(nomFichier);
    inputFile >> monde.L;
    inputFile >> monde.H;
    inputFile >> monde.Fx;
    inputFile >> monde.Fy;

    for(int i = 0; i < monde.L; i++) {
        aux.clear();
        for(int j = 0; j < monde.H; j++) {
            inputFile >> valeur;
            aux.push_back(valeur);
        }
        (monde.mat).push_back(aux);
    }

    inputFile.close();

    return monde;
}