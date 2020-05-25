#ifndef INVENTORY_H
#define INVENTORY_H

#include <mutex>
#include <map>
#include <string>

/*Clase que protege al inventario (recurso compartido) funcionando como 
monitor.*/
class Inventory {
	private:
		std::mutex m;
        std::map<char, int> resources;

	public:
    	/*Constructor de la clase.*/
        Inventory();

	    /*Agrega un recurso al mapa de recursos.*/
		/*Devuelve true en caso de exito, false si no.*/
		bool add(char resource);

		void print_map();

		/*Destructor de la clase.*/
		~Inventory();
};

#endif 
