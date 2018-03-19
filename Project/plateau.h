#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <list>
#include "tuile.h"

class Plateau : public QObject
{
    Q_OBJECT
public:
    explicit Plateau(QObject *parent = nullptr, int n = 4);

    void gravite(QString direction);
    void fusion(QString direction);
    void spawn();
    void gagne();
    void perdu();
    void reset();
    void initialiser();
    void bouger(QString direction);

    Q_PROPERTY(QString QML_2048 READ read2048 NOTIFY jeu_modif);
    QString read2048();


signals:
    void jeu_modif();

public slots:

private :
    Tuile tuiles[];
    int taille;
};

#endif // PLATEAU_H
