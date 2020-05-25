#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include "workers_parser.h"
#include "map_parser.h"
#include "thread.h"
#include "collector.h"
#include "blocking_queue.h"
#include "inventory.h"
#include "score.h"

#define PARAMS_AMOUNT 3
#define ERROR 1
#define SUCCESS 0
#define WORKERS_FILE 1
#define MAP_FILE 2

int main(int argc, const char *argv[]) {
    // Primero parseas el workers file creando los workers correspondientes
    // Que basically son threads, y los puedo almacenar en un vector de threads
    // Luego, vamos a spawnear a los trabajadores
    // Segundo parseo el mapa y los voy asignando a sus colas bloqueantes
    // A medida que voy leyendo el mapa en main una por cada tipo de worker
    // Y aca va a haber que proteger al inventario porque es shared
    // Tanto por los producers como los consumers.
    // Ademas setearemos una condition variable q no le permita a los consumers
    // Consumir, hasta que tenga los recursos que necesita para sumar 1 pto.
    // Segun la recomendacion hay q usar una sola condition variable.

    if (argc != PARAMS_AMOUNT) {
        printf("Uso: ./tp <workersfile> <mapfile>\n");
    	return ERROR;
    }

	WorkersParser workers_parser(argv[WORKERS_FILE]);
    MapParser map_parser(argv[MAP_FILE]);
    BlockingQueue farmers_queue, miners_queue, woodcutters_queue;
    std::vector<std::thread> collectors, producers;
    Inventory inventory;
    Score score;

    workers_parser.run_workers(collectors, producers, farmers_queue, miners_queue, 
        woodcutters_queue, inventory, score);
    map_parser.fill_queues(farmers_queue, miners_queue, woodcutters_queue, inventory);
    workers_parser.join_collectors(collectors);
    inventory.deactivate();
    workers_parser.join_producers(producers);
    
    inventory.print_map();
    score.print_score();
	return SUCCESS;
}
