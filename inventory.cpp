#include "inventory.h"
#include "exceptions.h"
#include <string>
#include <iostream>
#include <map>

#define WHEAT 'T'
#define WOODS 'M'
#define COAL 'C'
#define IRON 'H'

bool Inventory::add(char resource) {
    std::unique_lock<std::mutex> lk(m);
    if (resources.find(resource) == resources.end()) {
        // not found
        resources[resource] = 1;
        cv.notify_all();
        return true;
    } else {
        // found
        resources[resource] += 1;
        cv.notify_all();
        return true;
    }
    return false;
}

bool Inventory::remove(std::map<char, int> &recipe) {
    std::unique_lock<std::mutex> lk(m);
    while (!this->has_resources(recipe) && isActive) {
        cv.wait(lk);
    }
    if (!isActive) throw NoMoreResourcesException();    
    this->consume_resources(recipe);
    return true;
}

bool Inventory::has_resources(std::map<char, int> &recipe) {
    std::map<char, int>::iterator it = recipe.begin();
    bool can_remove = true;

    while (it != recipe.end()) {
        char resource = it->first;
        int amount_needed = it->second;
        if (resources[resource] < amount_needed) {
            can_remove = false;
            break;
        }
        it++;
    }
    return can_remove;
}

void Inventory::consume_resources(std::map<char, int> &recipe) {
    std::map<char, int>::iterator it = recipe.begin();

    while (it != recipe.end()) {
        char resource = it->first;
        int amount_needed = it->second;
        resources[resource] -= amount_needed;
        it++;
    }
}


void Inventory::deactivate() {
    std::unique_lock<std::mutex> lk(m);
    isActive = false;
    cv.notify_all();
}

void Inventory::print_inventory() {
    std::cout << "Recursos restantes:" << '\n';
    std::cout << "  - Trigo: " << resources[WHEAT] << '\n';
    std::cout << "  - Madera: " << resources[WOODS] << '\n';
    std::cout << "  - Carbon: " << resources[COAL] << '\n';
    std::cout << "  - Hierro: " << resources[IRON] << '\n';
    std::cout << '\n';
}

Inventory::~Inventory() {}
