#include "carpenter.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define WOOD_AMOUNT 3
#define IRON_AMOUNT 1
#define WOODS 'M'
#define IRON 'H'
#define BENEFIT_POINTS 2

void Carpenter::run() {
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
    recipe[WOODS] = WOOD_AMOUNT;
    recipe[IRON] = IRON_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Carpenter::~Carpenter() {}
