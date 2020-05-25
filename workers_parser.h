#ifndef WORKERS_PARSER_H
#define WORKERS_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>
#include <thread>
#include <string>
#include "thread.h"
#include "blocking_queue.h"
#include "collector.h"
#include "producer.h"
#include "inventory.h"

/*Clase que lee el archivo de trabajadores cuando se inicia el programa.*/
class WorkersParser {
private:
    std::fstream workers_file;
    const char *file;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    explicit WorkersParser(const char* filename);

    /*Crea los trabajadores y los agrega al vector de colectores/productores 
    respectivamente.*/
    // void create_workers(std::vector<Collector*> &collectors, 
    //     std::vector<Producer*> &producers);

    /*.*/
    void run_collectors(std::vector<std::thread> &collectors, 
        BlockingQueue &farmers_queue,
        BlockingQueue &miners_queue, 
        BlockingQueue &woodcutters_queue,
        Inventory &inventory);

    /*.*/
    void run_producers(std::vector<Producer*> &producers,
        Inventory &inventory);

    void join_collectors(std::vector<std::thread> &collectors);

    /*Parsea las lineas del archivo a un mapa con cada worker y su cantidad.*/
    std::map<std::string, int> map_line();

    /*Devuelve verdadero si es recolector, falso sino.*/
    bool is_collector(std::string worker_role);

    /*Devuelve verdadero si es productor, falso sino.*/
    bool is_producer(std::string worker_role);

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~WorkersParser();
};

#endif // WORKERS_PARSER_H
