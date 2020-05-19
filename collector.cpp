#include "collector.h"
#include <iostream>
#include <string>
#include <mutex>

Collector::Collector(const std::string &type, std::mutex &m) :
	type(type), m(m) {}

void Collector::run() {
}

Collector::~Collector() {
}
