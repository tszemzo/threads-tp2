#include "chef.h"
#include <iostream>

void Chef::operator()() {
    std::cout << "Chef running" << '\n';
}

Chef::~Chef() {}
