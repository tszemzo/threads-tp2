#ifndef WORKERS_PARSER_H
#define WORKERS_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>
#include "thread.h"

/*Clase que lee el archivo de trabajadores cuando se inicia el programa.*/
class WorkersParser {
private:
    std::fstream workers_file;
    const char *file;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    WorkersParser(const char* filename);

    /*Crea los trabajadores parseados.*/
    void create_workers(std::vector<Thread*> collectors, std::vector<Thread*> producers);

    /*Parsea una linea del archivo.*/
    std::map<std::string, int> map_line();

    /*Devuelve verdadero si es recolector, falso sino.*/
    bool is_collector(std::string worker_role);

    /*Devuelve verdadero si es productor, falso sino.*/
    bool is_producer(std::string worker_role);

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~WorkersParser();
};

#endif // WORKERS_PARSER_H
