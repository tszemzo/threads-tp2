#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"
#include "inventory.h"
#include "score.h"

/*Clase que representa a una memoria cache directa. Hereda de la clase
Cache.*/
class Chef {
	private:
		Inventory &inventory;
		Score &score;

	public:
		/*Constructor de la clase.*/
		Chef(Inventory &inventory, Score &score) : 
			inventory(inventory), score(score) {}

		void operator()();

		void produce();
		
		/*Destructor de la clase.*/
		~Chef();
};

#endif 
