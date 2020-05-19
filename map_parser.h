#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <stdlib.h>
#include <fstream>
#include "blocking_queue.h"

/*Clase que lee el archivo del mapa cuando se inicia el programa.*/
class MapParser {
private:
    std::fstream map_file;
    const char *file;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    explicit MapParser(const char* filename);

     /*Llena las colas bloqueantes con los recursos obtenidos del archivo.*/
    void fill_queues(BlockingQueue<char> &farmers_queue, 
                     BlockingQueue<char> &miners_queue,
                     BlockingQueue<char> &woodcutters_queue);

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~MapParser();
};

#endif // MAP_PARSER_H