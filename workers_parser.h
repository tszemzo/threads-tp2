#ifndef WORKERS_PARSER_H
#define WORKERS_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <map>

/*Clase que lee el archivo de trabajadores cuando se inicia el programa.*/
class WorkersParser {
private:
    std::fstream workers_file;
    const char *file;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    WorkersParser(const char* filename);

    /*Lee el archivo que tiene como atributo y crea los trabajadores parseados.*/
    void read_and_create_workers();

    /*Parsea una linea del archivo.*/
    bool parse_line(std::map<std::string, int> map_of_workers);

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~WorkersParser();
};

#endif // WORKERS_PARSER_H
