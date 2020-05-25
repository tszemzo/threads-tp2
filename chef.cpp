#include "chef.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <unistd.h>

#define WORK_TIME 60
#define WHEAT_AMOUNT 2
#define COAL_AMOUNT 1
#define BENEFIT_POINTS 5

void Chef::operator()() {
    // std::cout << "Chef running" << '\n';
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
    recipe['T'] = WHEAT_AMOUNT;
    recipe['C'] = COAL_AMOUNT;
    inventory.remove(recipe);
    score.add(BENEFIT_POINTS);
}

Chef::~Chef() {}
