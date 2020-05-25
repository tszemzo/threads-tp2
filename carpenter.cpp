#include "carpenter.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define WOOD_AMOUNT 3
#define IRON_AMOUNT 1
#define BENEFIT_POINTS 2

void Carpenter::operator()() {
    std::cout << "C rarpenterunning" << '\n';
    while (true) {
        try {
            this->produce();
            usleep(WORK_TIME);
        } catch(NoMoreResourcesException) {
            break;
        }
    }
}

void Carpenter::produce() {
    std::map<char, int> recipe;
    recipe['M'] = WOOD_AMOUNT;
    recipe['H'] = IRON_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Carpenter::~Carpenter() {}
