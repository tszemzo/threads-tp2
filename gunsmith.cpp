#include "gunsmith.h"
#include <iostream>

void Gunsmith::operator()() {
    std::cout << "Gunsmith running" << '\n';
}

Gunsmith::~Gunsmith() {}
