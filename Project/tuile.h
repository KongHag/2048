#ifndef TUILE_H
#define TUILE_H

#include <QObject>
#include <list>

class Tuile : public QObject
{
    Q_OBJECT
public:
    explicit Tuile(QObject *parent = nullptr, int indice = 0);

    void changer_valeur(int new_val);


signals:

public slots:

private :
    int valeur;
    int coordonnees[2];

};

#endif // TUILE_H
