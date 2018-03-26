#include "plateau.h"
#include "tuile.h"
#include <stdlib.h>
#include <list>

Plateau::Plateau(QObject *parent, int n) : QObject(parent)
{
    taille = n;
    QList<Tuile> tuiles;
    for (int i=0;i<taille*taille;i++){
        Tuile tuilevide;
        tuiles.append(tuilevide);
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
    QList<int> liste_cases_vides;
    for (int i=0; i<taille*taille; i++){
        if (tuiles[i].valeur == 0){
            liste_cases_vides.append(i);
        }
    }
    if (liste_cases_vides.size()==0) {
        perdu();
    }
    else {
        int new_spawn = rand()%liste_cases_vides.size();
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
    if (direction==1){
        for (int i=taille-1; i<taille*taille; i++){
            int j = i;
            while(tuiles[j-taille].valeur==0 && j>=0){
                tuiles[j-taille].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j = j-taille;
            }
        }
    }
   else if (direction==2){
        for(int k=0, s=tuiles.size(), max=(s/2); k<max; k++) tuiles.swap(k,s-(1+k));
        for (int i=taille-1; i<taille*taille; i++){
            int j = i;
            while(tuiles[j-taille].valeur==0 && j>=0){
                tuiles[j-taille].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j = j-taille;
            }
        }
        for(int k=0, s=tuiles.size(), max=(s/2); k<max; k++) tuiles.swap(k,s-(1+k));
}
    else if (direction==3){
        for (int i=0; i<taille*taille; i++){
            int j = i;
            int mult = j/4;
            while(tuiles[j-1].valeur == 0 && j/4 == mult){
                tuiles[j-1].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j=j-1;
            }
        }
}
    else if (direction==4){
        for(int k=0, s=tuiles.size(), max=(s/2); k<max; k++) tuiles.swap(k,s-(1+k));
        for (int i=0; i<taille*taille; i++){
            int j = i;
            int mult = j/4;
            while(tuiles[j-1].valeur == 0 && j/4 == mult){
                tuiles[j-1].changer_valeur(tuiles[j].valeur);
                tuiles[j].changer_valeur(0);
                j=j-1;
            }
        }
        for(int k=0, s=tuiles.size(), max=(s/2); k<max; k++) tuiles.swap(k,s-(1+k));
    }
    }


void Plateau::fusion(QString direction) {

}
