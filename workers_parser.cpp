#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <thread>
#include "workers_parser.h"

WorkersParser::WorkersParser(const char *filename) {
	workers_file.open(filename, std::fstream::in);
	if (!workers_file.is_open()) {
		std::cerr << filename << ": Couldn't open the file." << std::endl;
	}
}

std::map<std::string, int> WorkersParser::map_line() {
    std::map<std::string, int> map_of_workers;
    std::string line;
    int start_of_word = 0;

    while (!workers_file.eof()) {
        start_of_word = 0;
        std::getline(workers_file, line, '\n');
        if (line.length() <= 0) break;
        std::string key = line.substr(start_of_word, line.find('='));
        start_of_word = key.length() + 1;
        std::string value = line.substr(start_of_word, line.find('\n'));
        int amount = std::stoi(value);
        map_of_workers[key] = amount;
	}
    return map_of_workers;
}

void WorkersParser::run_workers(std::vector<std::thread> &collectors,
    std::vector<ProducerThread*> &producers, 
    BlockingQueue &farmers_queue,
    BlockingQueue &miners_queue, 
    BlockingQueue &woodcutters_queue,
    Inventory &inventory,
    Score &score) {
    std::map<std::string, int> map_of_workers = this->map_line();

    for (int i = 0; i < map_of_workers["Agricultores"]; i++) {
        collectors.push_back(std::thread { 
            Collector(farmers_queue, inventory) 
        });
    }
    for (int i = 0; i < map_of_workers["Leniadores"]; i++) {
        collectors.push_back(std::thread { 
            Collector(woodcutters_queue, inventory) 
        });
    }
    for (int i = 0; i < map_of_workers["Mineros"]; i++) {
        collectors.push_back(std::thread { 
            Collector(miners_queue, inventory) 
        });
    }
    for (int i = 0; i < map_of_workers["Cocineros"]; i++) {
        ProducerThread *t = new Chef(inventory, score);
        t->start();
        producers.push_back(t);
    }
    for (int i = 0; i < map_of_workers["Carpinteros"]; i++) {
        ProducerThread *t = new Carpenter(inventory, score);
        t->start();
        producers.push_back(t);
    }
    for (int i = 0; i < map_of_workers["Armeros"]; i++) {
        ProducerThread *t = new Gunsmith(inventory, score);
        t->start();
        producers.push_back(t);
    }
}

WorkersParser::~WorkersParser() {
	if(workers_file.is_open()) {
		workers_file.close();
	}
}
