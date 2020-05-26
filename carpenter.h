#ifndef CARPENTER_H
#define CARPENTER_H

#include <iostream>
#include <string>
#include <mutex>
#include "producer_thread.h"
#include "inventory.h"
#include "score.h"

/*Clase que representa a un carpintero.*/
class Carpenter : public ProducerThread {
	private:
		Inventory &inventory;
		Score &score;

	public:
		/*Constructor de la clase.*/
		Carpenter(Inventory &inventory, Score &score) : 
			inventory(inventory), score(score) {}

		void run() override;

		void produce();

		/*Destructor virtual de la clase.*/
		~Carpenter();
};

#endif 
