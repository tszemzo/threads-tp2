#ifndef PRODUCER_H
#define PRODUCER_H

#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"
#include "inventory.h"

// eliminar estos comentarios, 
// de donde sacaste lo de memoria cache? es cualquiera
/*Clase que representa a una memoria cache directa. Hereda de la clase
Cache.*/
class Producer: public Thread{
	private:
        std::string type;
        // el thread no debe de contener al mutex, es parte de la cola bloqueante
        std::mutex &m;

	public:
		/*Constructor de la clase.*/
		Producer(const std::string &type, std::mutex &m);

		void run(Inventory &inventory);

		/*Destructor virtual de la clase.*/
		virtual ~Producer();
};

#endif 
