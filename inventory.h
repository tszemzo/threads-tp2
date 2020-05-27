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

	    /* Agrega un recurso al inventario.*/
		/* Devuelve true en caso de exito, false si no.*/
		bool add(char resource);

		/* Consume recursos en caso de que tenga los contenidos
		 * en la receta y hace esperar a los threads en caso
		 * de que el inventario este activo pero aun no posea
		 * los recursos precisados
		 */
		bool remove(std::map<char, int> &recipe);

		/* Retorna verdadero o falso si el inventario posee
		 * los recursos que recibe en la receta por parametro
		 */
		bool has_resources(std::map<char, int> &recipe);

		/* Consume recursos del inventario en caso de que posea 
		 * los recursos que recibe en la receta por parametro
		 */
		void consume_resources(std::map<char, int> &recipe);

		/* Desactiva el inventario notificando a los threads */
		void deactivate();

		/* Imprime los recursos restantes del inventario por pantalla */
		void print_inventory();

		/*Destructor de la clase.*/
		~Inventory();
};

#endif 
