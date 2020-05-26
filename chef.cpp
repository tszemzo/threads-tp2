#include "chef.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define WHEAT_AMOUNT 2
#define COAL_AMOUNT 1
#define WHEAT 'T'
#define COAL 'C'
#define BENEFIT_POINTS 5

void Chef::run() {
    while (true) {
        try {
            this->produce();
            usleep(WORK_TIME);
        } catch(NoMoreResourcesException) {
            break;
        }
    }
}

void Chef::produce() {
    std::map<char, int> recipe;
    recipe[WHEAT] = WHEAT_AMOUNT;
    recipe[COAL] = COAL_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Chef::~Chef() {}
