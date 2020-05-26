#include "gunsmith.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define COAL_AMOUNT 2
#define IRON_AMOUNT 2
#define COAL 'C'
#define IRON 'H'
#define BENEFIT_POINTS 3

void Gunsmith::run() {
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
    recipe[COAL] = COAL_AMOUNT;
    recipe[IRON] = IRON_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Gunsmith::~Gunsmith() {}
