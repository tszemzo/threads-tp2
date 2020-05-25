#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "thread.h"
#include "inventory.h"
#include "blocking_queue.h"

#define WORK_TIME 50

/*Clase que representa a recolector va a funcionar como un hilo de ejecucion*/
class Collector {
	private:
		BlockingQueue &queue;
		Inventory &inventory;

	public:
		/*Constructor de la clase.*/
		Collector(BlockingQueue &queue, Inventory &inventory) : 
            queue(queue), inventory(inventory) {}

		void operator()();

		/*Destructor virtual de la clase.*/
		~Collector();
};

#endif 
