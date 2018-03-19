#include "plateau.h"
#include "tuile.h"
#include <stdlib.h>
#include <list>

Plateau::Plateau(QObject *parent, int n) : QObject(parent)
{
    taille = n;
    std::list<Tuile> tuiles;
    for (int i=0; i<taille*taille;i++){
        tuiles.push_back(Tuile(nullptr, i));
    }
    initialiser();
}

void Plateau::initialiser(){
    reset();
    spawn();
    spawn();
}

void Plateau::bouger(QString direction) {
    gravite(direction);
    fusion(direction);
    gravite(direction);
}

void Plateau::reset() {
    for (int i=0; i<taille*taille; i++){
        tuiles[i].changer_valeur(0);
    }
}

void Plateau::spawn() {
    int liste_cases_vides[];
    for (int i=0; i<taille*taille; i++){
        if (tuiles[i].valeur == 0){
            liste_cases_vides.push_back(i);
        }
    }
    if (liste_cases_vides.size==0) {
        perdu();
    }
    else {
        int new_spawn = rand()%liste_cases_vides.size;
        int new_value = (rand()%2+1)*2;
        tuiles[liste_cases_vides[new_spawn]].changer_valeur(new_value);
    }
}

void Plateau::perdu() {
    initialiser();
}

void Plateau::gagne() {
    initialiser();
}

void Plateau::gravite(QString direction){
    switch (direction){
        case("Haut"):
        for (int i=taille-1; i<taille*taille; i++){
            int j = i;
            while(tuiles[j-taille]==0 && j>=0){
                tuiles[j-taille].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j = j-taille;
            }
        }
        break;
    case("Bas"):
        tuiles.reverse();
        for (int i=taille-1; i<taille*taille; i++){
            int j = i;
            while(tuiles[j-taille]==0 && j>=0){
                tuiles[j-taille].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j = j-taille;
            }
        }
        tuiles.reverse();
    break;
    case("Gauche"):
        for (int i=0; i<taille*taille; i++){
            int j = i;
            int mult = j/4;
            while(tuiles[j-1] == 0 && j/4 == mult){
                tuiles[j-1].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j=j-1;
            }
        }
        break;
    case("Droite"):
        tuiles.reverse();
        for (int i=0; i<taille*taille; i++){
            int j = i;
            int mult = j/4;
            while(tuiles[j-1] == 0 && j/4 == mult){
                tuiles[j-1].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j=j-1;
            }
        }
        tuiles.reverse();
        break;
    }
}

void Plateau::fusion(QString direction) {

}
