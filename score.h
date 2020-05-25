#ifndef SCORE_H
#define SCORE_H

#include <mutex>

/*Clase que lee el archivo del mapa cuando se inicia el programa.*/
class Score {
private:
    int score;
    std::mutex m;

public:
    /*Crea el tanteador asignandole el archivo abierto 
    (se usa char *file para ello) como atribut.*/
    Score();

    bool add(int points);

    /*Destructor del objeto.*/
    ~Score();
};

#endif // SCORE_H
