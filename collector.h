#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"
#include "inventory.h"
#include "blocking_queue.h"

/*Clase que representa a recolector que va a funcionar como un hilo de ejecucion.
 Hereda de Thread por esta misma razon.*/
class Collector: public Thread{
	private:
        std::string type;
        std::mutex &m;

	public:
		/*Constructor de la clase.*/
		Collector(const std::string &type, std::mutex &m);

		void run(BlockingQueue<char> &farmers_queue, Inventory &inventory);

		std::string get_type();

		/*Destructor virtual de la clase.*/
		~Collector();
};

#endif 
