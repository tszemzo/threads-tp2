#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "inventory.h"
#include "blocking_queue.h"

/*Clase que representa a recolector va a funcionar como un hilo de ejecucion*/
class Collector {
	private:
		BlockingQueue &queue;
		Inventory &inventory;

	public:
		/* Constructor de la clase.*/
		Collector(BlockingQueue &queue, Inventory &inventory) : 
            queue(queue), inventory(inventory) {}

		/* Sobrecarga del operador ().
		 * Intenta trabajar y llevar al inventario un recurso
		 */
		void operator()();

		/* Destructor de la clase.*/
		~Collector();
};

#endif 
