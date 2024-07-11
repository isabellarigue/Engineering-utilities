#include "fourmi.h"
#include "proba.h"
#include "constantes.h"
#include <cmath>

void DeplaceFourmi1(t_fourmi& fourmi){
    int num;

    num = nalea(7);
    switch (num){
        case 0: //haut
            fourmi.y -= 1;
        case 1: //bas
            fourmi.y += 1;
        case 2: //gauche
            fourmi.x -= 1;
        case 3://droite
            fourmi.x += 1;
        case 4: //diagonal haut droit
            fourmi.x += 1;
            fourmi.y -= 1;
        case 5: //diagonal bas droit
            fourmi.x += 1;
            fourmi.y += 1;
        case 6: //diagonal haut gauche
            fourmi.x -= 1;
            fourmi.y -= 1;
        case 7: //diagonal bas gauche
            fourmi.x -= 1;
            fourmi.y += 1;

    }

}

int PositionPossible(int x, int y, t_monde monde) {
    if(x >= monde.L || x < 0 || y >= monde.H || y < 0 || monde.mat[y][x] == -1)
        return 0;
    return 1;   
}

int modulo8(int x) {
    return ((x + 8) % 8);
}

int positionNourriture(int x, int y, t_monde monde) {
    if(monde.mat[y][x] > 0 && x != monde.Fx && y != monde.Fy)
        return 1;
    return 0;
}

int DirFourmiliere(int x, int y, int Fx, int Fy) {
    int resultat;
    int dx = Fx - x;
    int dy = Fy - y;
    float norme = sqrt(dx*dx + dy*dy);
    
    dx = (int)round(dx/norme); // round retourne un réel qu’il faut transformer en entier
    dy = (int)round(dy/norme);
    
    for (int i = 0; i <= 7; i++){ // vérifier pour les 8 directions possibles celle qui oriente au mieux vers la fourmilière
        if(dx == tdx[i] && dy == tdy[i]) { 
            resultat = i;
        }
    }
    return resultat;
}

int arriveFourmiliere(int x, int y, t_monde monde) {
    if(x == monde.Fx && y == monde.Fy)
        return 1;
    return 0;
}

t_fourmi DeplaceFourmi(t_fourmi fourmi, t_monde environnement) { 
    int dir, i;
    t_poids ponderation; // pondération pour le tirage

    for(i = 0; i <= 7; i++) { // choix d’une direction
        dir = modulo8(i - fourmi.direction);
        if(fourmi.mode == 1) //cherche nourriture
            ponderation[i] = p_toutdroit[dir];
        else //vers fourmiliere
            ponderation[i] = p_fourmiliere[dir];
    }

    for(i = 0; i <= 7; i++) {  // pondération nulle quand le déplacement n’est pas possible
        if(! (PositionPossible(fourmi.x+tdx[i], fourmi.y+tdy[i], environnement) ) ) 
            ponderation[i] = 0;
        else { //position possible
            if(positionNourriture(fourmi.x+tdx[i], fourmi.y+tdy[i], environnement) && fourmi.mode == 1) { 
                ponderation[i] = 10000000;
            }
            //if(i == DirFourmiliere(fourmi.x+tdx[i], fourmi.y+tdy[i], environnement.Fx, environnement.Fy)) {
            if(fourmi.x+tdx[i] == environnement.Fx && fourmi.y+tdy[i] == environnement.Fy && fourmi.mode == 0){
                ponderation[i] = 10000000;
            }
        }
    }

    // détermination de la direction par tirage au sort suivant la pondération
    fourmi.direction = nalea_pondere(ponderation);

    // 2) déplacement suivant cette direction
    fourmi.x = fourmi.x + tdx[fourmi.direction];
    fourmi.y = fourmi.y + tdy[fourmi.direction];
    
    return fourmi;
}
