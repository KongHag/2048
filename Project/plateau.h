#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>

class Plateau : public QObject
{
    Q_OBJECT
public:
    explicit Plateau(QObject *parent = nullptr);

    void gravite(QString direction);
    void fusion(QString direction);
    void spawn();
    void gagne();
    void perdu();
    void reset();
    void initialiser();
    void bouger(QString direction);

    Q_PROPERTY(QString QML_2048 READ read2048 NOTIFY 2048modif);
    QString read2048();


signals:
    void 2048modif();

public slots:

private :
    list<Tuile> tuiles;
    int taille;
};

#endif // PLATEAU_H
