#include <vector>
#include "orchestrator.h"

void Orchestrator::run(const char* workers_file, const char* map_file) {
    WorkersParser workers_parser(workers_file);
    MapParser map_parser(map_file);
    BlockingQueue farmers_queue, miners_queue, woodcutters_queue;
    std::vector<std::thread> collectors;
    std::vector<ProducerThread*> producers;
    Inventory inventory;
    Score score;

    workers_parser.run_workers(collectors, producers, farmers_queue, 
        miners_queue, woodcutters_queue, inventory, score);
    map_parser.fill_queues(farmers_queue, miners_queue, woodcutters_queue);
    this->join_collectors(collectors);
    inventory.deactivate();
    this->join_producers(producers);
    this->print_results(inventory, score);
}

void Orchestrator::join_collectors(std::vector<std::thread> &collectors) {
    for (unsigned int i = 0; i < collectors.size(); ++i) {
        collectors[i].join();
    }
}

void Orchestrator::join_producers(std::vector<ProducerThread*> &producers) {
    for (unsigned int i = 0; i < producers.size(); ++i) {
        producers[i]->join();
        delete producers[i];
    }
}

void Orchestrator::print_results(Inventory &inventory, Score &score) {
    inventory.print_map();
    score.print_score();
}
