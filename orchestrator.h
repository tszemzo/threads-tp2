#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <string>
#include <vector>
#include "workers_parser.h"
#include "map_parser.h"
#include "producer_thread.h"
#include "collector.h"
#include "blocking_queue.h"
#include "producer_thread.h"
#include "inventory.h"
#include "score.h"

/*Clase que orquesta al hilo principal de ejecucion*/
class Orchestrator {
	public:
    	/*Constructor de la clase.*/
        Orchestrator() {}

        void run(const char* workers_file, const char* map_file);

        void join_collectors(std::vector<std::thread> &collectors);

        void join_producers(std::vector<ProducerThread*> &producers);

        void print_results(Inventory &inventory, Score &score);

		/*Destructor de la clase.*/
		~Orchestrator() {}
};

#endif 
