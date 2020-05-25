#include "gunsmith.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define COAL_AMOUNT 2
#define IRON_AMOUNT 2
#define BENEFIT_POINTS 3

void Gunsmith::operator()() {
    // std::cout << "Gunsmith running" << '\n';
    while (true) {
        try {
            this->produce();
            usleep(WORK_TIME);
        } catch(NoMoreResourcesException) {
            break;
        }
    }
}

void Gunsmith::produce() {
    std::map<char, int> recipe;
    recipe['C'] = COAL_AMOUNT;
    recipe['H'] = IRON_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Gunsmith::~Gunsmith() {}
