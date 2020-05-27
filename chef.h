#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>
#include <mutex>
#include "producer_thread.h"
#include "inventory.h"
#include "score.h"

/* Clase que representa a un Chef del modelo
 * Esta implementado heredando de ProducerThread
 * Por lo que es un objeto "vivo" que tiene sus atributos 
 * y su logica (una tarea) pero que vive en su propio hilo
 */
class Chef : public ProducerThread {
	private:
		Inventory &inventory;
		Score &score;

	public:
		/*Constructor de la clase.*/
		Chef(Inventory &inventory, Score &score) : 
			inventory(inventory), score(score) {}

		/*Corre al hilo en cuestion.*/
		void run() override;

		/*Intenta producir recursos en puntos de beneficio.*/
		void produce();
		
		/*Destructor de la clase.*/
		~Chef();
};

#endif 
