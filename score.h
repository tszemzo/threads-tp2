#ifndef SCORE_H
#define SCORE_H

#include <mutex>
#include <iostream>

/*Clase que modela el tanteador del programa.*/
class Score {
private:
    int score;
    std::mutex m;

public:
    /*Constructor del tanteador.*/
    Score();

    /*Crea "points" puntos al tanteador*/
    bool add(int points);

    /*Imprime por pantalla los puntos del tanteador*/
    void print_score();

    /*Destructor del objeto.*/
    ~Score();
};

#endif // SCORE_H
