#ifndef TUILE_H
#define TUILE_H

#include <QObject>

class Tuile : public QObject
{
    Q_OBJECT
public:
    explicit Tuile(QObject *parent = nullptr, int indice);

    void changer_valeur(int new_val);


signals:

public slots:

private :
    int valeur;
    list<int> coordonnees;

};

#endif // TUILE_H
