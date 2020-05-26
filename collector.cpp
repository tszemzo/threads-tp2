#include "collector.h"
#include "exceptions.h"

#define WORK_TIME 50

void Collector::operator()() {
    while (true) {
        try {
            char resource = queue.pop();
            usleep(WORK_TIME);
            inventory.add(resource);
        } catch(ClosedQueueException) {
            break;
        }
    }
}

Collector::~Collector() {}
