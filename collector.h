#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"


/*Clase que representa a una memoria cache directa. Hereda de la clase
Cache.*/
class Collector: public Thread{
	private:
        std::string type;
        std::mutex &m;

	public:
		/*Constructor de la clase.*/
		Collector(const std::string &type, std::mutex &m);

		virtual void run();

		/*Destructor virtual de la clase.*/
		virtual ~Collector();
};

#endif 
