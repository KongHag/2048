#include "tuile.h"

Tuile::Tuile(QObject *parent, int indice) : QObject(parent)
{
    valeur = 0;
    coordonnees = list(indice/parent->taille,indice%parent->taille);
}

Tuile::changer_valeur(int new_val){
    valeur = new_val;
}
