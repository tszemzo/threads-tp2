#include <iostream>
#include <string>
#include "map_parser.h"
#include "blocking_queue.h"

#define WHEAT 'T'
#define WOODS 'M'
#define COAL 'C'
#define IRON 'H'

MapParser::MapParser(const char *filename) {
	map_file.open(filename, std::fstream::in);
	if (!map_file.is_open()) {
		std::cerr << filename << ": Couldn't open the file." << std::endl;
	}
}

void MapParser::fill_queues(BlockingQueue &farmers_queue, 
                            BlockingQueue &miners_queue,
                            BlockingQueue &woodcutters_queue) {
    std::string line;
    char delimiter{ '\n' };
    while (!map_file.eof()) {
        std::getline(map_file, line, delimiter);
        if (line.length() <= 0) break;
        for (unsigned int i = 0; i < line.length(); i++) {
            char resource = line[i];
            if (resource == WHEAT) farmers_queue.push(resource);
            if (resource == WOODS) woodcutters_queue.push(resource);
            if (resource == COAL || resource == IRON) { 
                miners_queue.push(resource);
            }
        }  
	}
    
    farmers_queue.close();
    woodcutters_queue.close();
    miners_queue.close();
}

MapParser::~MapParser() {
	if(map_file.is_open()) {
		map_file.close();
	}
}
