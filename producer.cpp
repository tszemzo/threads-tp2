#include "producer.h"
#include <iostream>
#include <string>
#include <mutex>

Producer::Producer(const std::string &type, std::mutex &m) :
	type(type), m(m) {}

void Producer::run() {
}

Producer::~Producer() {
}