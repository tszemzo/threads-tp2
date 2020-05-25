#include "collector.h"
#include "exceptions.h"

void Collector::operator()() {
    std::cout << "Collector running" << '\n';
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
