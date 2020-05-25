#include "inventory.h"
#include <string>
#include <iostream>
#include <mutex>

Inventory::Inventory() {}

bool Inventory::add(char resource) {
    std::unique_lock<std::mutex> lk(m);
    if (resources.find(resource) == resources.end()) {
        // not found
        resources[resource] = 1;
        return true;
    } else {
        // found
        resources[resource] += 1;
        return true;
    }
    return false;
}

void Inventory::print_map() {
    std::cout << "Madera added: " << resources['M'] << '\n';
    std::cout << "Hierro added: " << resources['H'] << '\n';
    std::cout << "Trigo added: " << resources['T'] << '\n';
    std::cout << "Carbon added: " << resources['C'] << '\n';
}

Inventory::~Inventory() {
}
