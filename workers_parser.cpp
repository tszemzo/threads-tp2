#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "workers_parser.h"
#include "collector.h"

WorkersParser::WorkersParser(const char *filename) {
	workers_file.open(filename, std::fstream::in);
	if (!workers_file.is_open()) {
		std::cerr << filename << ": Couldn't open the file."
		<< std::endl;
	}
}

void WorkersParser::read_and_create_workers() {
    std::map<std::string, int> map_of_workers;
    while(!workers_file.eof()) {
        this->parse_line(map_of_workers);
	}

    std::map<std::string, int>::iterator it = map_of_workers.begin();
    while (it != map_of_workers.end()) {
        std::cout<< it->first <<" : "<< it->second <<std::endl;
        it++;
    }
    
}

bool WorkersParser::parse_line(std::map<std::string, int> map_of_workers) {
    std::string line;
    std::string delimiter = "=";
    int start_of_word = 0;

    std::getline(workers_file, line, '\n');
    if (line.length() <= 0) return false;
    std::string key = line.substr(start_of_word, line.find(delimiter));
    start_of_word = key.length() + delimiter.length();
    std::string value = line.substr(start_of_word, line.find('\n'));
    int amount = std::stoi(value);
    map_of_workers[key] = amount;
    std::cout << key << '\n';
    std::cout << value << '\n';
    return true;
}

WorkersParser::~WorkersParser() {
	if(workers_file.is_open()) {
		workers_file.close();
	}
}