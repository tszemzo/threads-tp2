#include "collector.h"
#include <iostream>
#include <string>
#include <mutex>

Collector::Collector(const std::string &type, std::mutex &m) :
	type(type), m(m) {}

void Collector::run(BlockingQueue<char> &blocking_queue, Inventory &inventory) {
	// implementar
	std::cout << "Collector running" << '\n';
}
// std::string&
std::string Collector::get_type() {
	return type;
}

Collector::~Collector() {
}
