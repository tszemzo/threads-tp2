#include "producer.h"
#include "inventory.h"
#include <iostream>
#include <string>
#include <mutex>

Producer::Producer(const std::string &type, std::mutex &m) :
	type(type), m(m) {}

void Producer::run(Inventory &inventory) {
	// implementar
	std::cout << "Producer Running." << '\n';
}

Producer::~Producer() {
}
