#include <iostream>
#include <string>
#include "map_parser.h"
#include "blocking_queue.h"

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
    char wheat{ 'T' };
    char woods{ 'M' };
    char coal{ 'C' };
    char iron{ 'H' };

    while (!map_file.eof()) {
        std::getline(map_file, line, delimiter);
        if (line.length() <= 0) break;
        for (unsigned int i = 0; i < line.length(); i++) {
            char resource = line[i];
            if (resource == wheat) farmers_queue.push(resource);
            if (resource == woods) woodcutters_queue.push(resource);
            if (resource == coal || resource == iron) {
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
