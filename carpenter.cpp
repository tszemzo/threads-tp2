#include "carpenter.h"
#include <iostream>

void Carpenter::operator()() {
    std::cout << "Carpenter running" << '\n';
}

Carpenter::~Carpenter() {}
