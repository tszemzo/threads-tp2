#ifndef INVENTORY_H
#define INVENTORY_H

#include <mutex>
#include <map>
#include <string>
#include <condition_variable>

/*Clase que protege al inventario (recurso compartido) funcionando como 
monitor.*/
class Inventory {
	private:
		bool isActive;
		std::mutex m;
        std::map<char, int> resources;
		std::condition_variable cv;

	public:
    	/*Constructor de la clase.*/
        Inventory(): isActive(true) {}
	    /*Agrega un recurso al mapa de recursos.*/
		/*Devuelve true en caso de exito, false si no.*/
		bool add(char resource);

		bool remove(std::map<char, int> &recipe);

		bool has_resources(std::map<char, int> &recipe);

		void consume_resources(std::map<char, int> &recipe);

		void deactivate();

		void print_map();

		/*Destructor de la clase.*/
		~Inventory();
};

#endif 
