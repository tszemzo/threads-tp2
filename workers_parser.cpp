#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <mutex>
#include "workers_parser.h"

WorkersParser::WorkersParser(const char *filename) {
	workers_file.open(filename, std::fstream::in);
	if (!workers_file.is_open()) {
		std::cerr << filename << ": Couldn't open the file." << std::endl;
	}
}

void WorkersParser::create_workers(std::vector<Collector*> &collectors, 
    std::vector<Producer*> &producers) {
    std::map<std::string, int> map_of_workers = this->map_line();
    std::map<std::string, int>::iterator it = map_of_workers.begin();
    std::mutex m;
    
    while (it != map_of_workers.end()) {
        std::string worker_role = it->first;
        int worker_amount = it->second;
        for (int i = 0; i < worker_amount; i++) {
            if (this->is_collector(worker_role)){
                Collector *collector = new Collector(worker_role, m);
                collectors.push_back(collector);
            } else {
                Producer *producer = new Producer(worker_role, m);
                producers.push_back(producer);
            }
        }
        
        std::cout<< it->first <<" : "<< it->second <<std::endl;
        it++;
    }
}

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

void WorkersParser::run_collectors(std::vector<Collector*> &collectors, 
    BlockingQueue<char> &farmers_queue,
    BlockingQueue<char> &miners_queue, 
    BlockingQueue<char> &woodcutters_queue,
    Inventory &inventory) {
    for (unsigned int i = 0; i < collectors.size(); i++) {
        Collector *current = collectors[i];
        if (current->get_type() == "Agricultores"){
            current->run(farmers_queue, inventory);
        }
        if (current->get_type() == "Leniadores"){
            current->run(woodcutters_queue, inventory);
        }
        if (current->get_type() == "Mineros"){
            current->run(miners_queue, inventory);
        }
    }
}

void WorkersParser::run_producers(std::vector<Producer*> &producers,
    Inventory &inventory){
    for (unsigned int i = 0; i < producers.size(); i++) {
        Producer *current = producers[i];
        current->run(inventory);
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
