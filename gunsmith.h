#ifndef GUNSMITH_H
#define GUNSMITH_H

#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"
#include "inventory.h"
#include "score.h"

/*Clase que representa a una memoria cache directa. Hereda de la clase
Cache.*/
class Gunsmith {
	private:
		Inventory &inventory;
		Score &score;

	public:
		/*Constructor de la clase.*/
		Gunsmith(Inventory &inventory, Score &score) : 
			inventory(inventory), score(score) {}

		void operator()();

		void produce();

		/*Destructor virtual de la clase.*/
		~Gunsmith();
};

#endif 
