#include <iostream>
#include "orchestrator.h"

#define PARAMS_AMOUNT 3
#define ERROR 1
#define SUCCESS 0
#define WORKERS_FILE 1
#define MAP_FILE 2

int main(int argc, const char *argv[]) {
    if (argc != PARAMS_AMOUNT) {
        printf("Uso: ./tp <workersfile> <mapfile>\n");
    	return ERROR;
    }

    Orchestrator orchestrator;
    orchestrator.run(argv[WORKERS_FILE], argv[MAP_FILE]);
	return SUCCESS;
}
