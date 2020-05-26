#ifndef WORKERS_PARSER_H
#define WORKERS_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>
#include <thread>
#include <string>
#include "producer_thread.h"
#include "blocking_queue.h"
#include "collector.h"
#include "chef.h"
#include "gunsmith.h"
#include "carpenter.h"
#include "inventory.h"
#include "score.h"

/*Clase que lee el archivo de trabajadores cuando se inicia el programa.*/
class WorkersParser {
private:
    std::fstream workers_file;
    const char *file;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    explicit WorkersParser(const char* filename);

    /*.*/
    void run_workers(std::vector<std::thread> &collectors,
        std::vector<ProducerThread*> &producers, 
        BlockingQueue &farmers_queue,
        BlockingQueue &miners_queue, 
        BlockingQueue &woodcutters_queue,
        Inventory &inventory,
        Score &score);

    void join_collectors(std::vector<std::thread> &collectors);

    void join_producers(std::vector<ProducerThread*> &producers);

    /*Parsea las lineas del archivo a un mapa con cada worker y su cantidad.*/
    std::map<std::string, int> map_line();

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~WorkersParser();
};

#endif // WORKERS_PARSER_H
