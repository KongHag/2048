#include "plateau.h"
#include "tuile.h"
#include <stdlib.h>

Plateau::Plateau(QObject *parent) : QObject(parent)
{
    initialiser();
}

Plateau::initialiser(){
    reset();
    spawn();
    spawn();
}

Plateau::bouger(QString direction) {
    gravite(direction);
    fusion(direction);
    gravite(direction);
}

Plateau::reset() {
    for (i=0; i<taille*taille-1; i++){
        tuiles[i].changer_valeur(0);
    }
}

Plateau::spawn() {
    list<int> liste_cases_vides = [];
    for (i=0; i<taille*taille-1; i++){
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

Plateau::perdu() {
    initialiser();
}

Plateau::gagne() {
    initialiser();
}

Plateau::gravite(QString direction){
    switch (direction){
        case("Haut"):
        for (i=taille-1; i<taille*taille-1; i++){
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
        for (i=taille-1; i<taille*taille-1; i++){
            int j = i;
            while(tuiles[j-taille]==0 && j>=0){
                tuiles[j-taille].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j = j-taille;
            }
        }
        tuiles.reverse();
    break;
    case("Droite"):
        break;
    case("Gauche"):
        break;
    }
}

Plateau::fusion(QString direction) {

}
