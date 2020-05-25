#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <mutex>
#include <thread>
#include "workers_parser.h"

WorkersParser::WorkersParser(const char *filename) {
	workers_file.open(filename, std::fstream::in);
	if (!workers_file.is_open()) {
		std::cerr << filename << ": Couldn't open the file." << std::endl;
	}
}

// void WorkersParser::create_workers(std::vector<Collector*> &collectors, 
//     std::vector<Producer*> &producers) {
//     std::map<std::string, int> map_of_workers = this->map_line();
//     std::map<std::string, int>::iterator it = map_of_workers.begin();
//     std::mutex m;
    
//     while (it != map_of_workers.end()) {
//         std::string worker_role = it->first;
//         int worker_amount = it->second;
//         for (int i = 0; i < worker_amount; i++) {
//             if (this->is_collector(worker_role)){
//                 Collector *collector = new Collector(worker_role, m);
//                 collectors.push_back(collector);
//             } else {
//                 Producer *producer = new Producer(worker_role, m);
//                 producers.push_back(producer);
//             }
//         }
        
//         std::cout<< it->first <<" : "<< it->second <<std::endl;
//         it++;
//     }
// }

std::map<std::string, int> WorkersParser::map_line() {
    std::map<std::string, int> map_of_workers;
    std::string line;
    std::string delimiter = "=";
    int start_of_word = 0;

    while (!workers_file.eof()) {
        start_of_word = 0;
        std::getline(workers_file, line, '\n');
        if (line.length() <= 0) break;
        std::string key = line.substr(start_of_word, line.find(delimiter));
        start_of_word = key.length() + delimiter.length();
        std::string value = line.substr(start_of_word, line.find('\n'));
        int amount = std::stoi(value);
        map_of_workers[key] = amount;
	}
    return map_of_workers;
}

void WorkersParser::run_collectors(std::vector<std::thread> &collectors, 
    BlockingQueue &farmers_queue,
    BlockingQueue &miners_queue, 
    BlockingQueue &woodcutters_queue,
    Inventory &inventory) {
    std::map<std::string, int> map_of_workers = this->map_line();

    for (int i = 0; i < map_of_workers["Agricultores"]; i++) {
        collectors.push_back(std::thread { Collector(farmers_queue, inventory) });
    }
    for (int i = 0; i < map_of_workers["Leniadores"]; i++) {
        collectors.push_back(std::thread { Collector(woodcutters_queue, inventory) });
    }
    for (int i = 0; i < map_of_workers["Mineros"]; i++) {
        collectors.push_back(std::thread { Collector(miners_queue, inventory) });
    }
}

void WorkersParser::run_producers(std::vector<Producer*> &producers,
    Inventory &inventory){
    for (unsigned int i = 0; i < producers.size(); i++) {
        Producer *current = producers[i];
        current->run(inventory);
    }
}

void WorkersParser::join_collectors(std::vector<std::thread> &collectors) {
    for (unsigned int i = 0; i < collectors.size(); ++i) {
        collectors[i].join();
    }
}

bool WorkersParser::is_collector(std::string worker_role) {
    return worker_role.compare("Agricultores") == 0 || 
           worker_role.compare("Leniadores") == 0 || 
           worker_role.compare("Mineros") == 0;
}

bool WorkersParser::is_producer(std::string worker_role) {
    return worker_role.compare("Cocineros") == 0 || 
           worker_role.compare("Carpinteros") == 0 || 
           worker_role.compare("Armeros") == 0;
}

WorkersParser::~WorkersParser() {
	if(workers_file.is_open()) {
		workers_file.close();
	}
}
