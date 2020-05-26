#ifndef GUNSMITH_H
#define GUNSMITH_H

#include <iostream>
#include <string>
#include <mutex>
#include "producer_thread.h"
#include "inventory.h"
#include "score.h"

/*Clase que representa a un armero.*/
class Gunsmith : public ProducerThread {
	private:
		Inventory &inventory;
		Score &score;

	public:
		/*Constructor de la clase.*/
		Gunsmith(Inventory &inventory, Score &score) : 
			inventory(inventory), score(score) {}

		void run() override;

		void produce();

		/*Destructor virtual de la clase.*/
		~Gunsmith();
};

#endif 
