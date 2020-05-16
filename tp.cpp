#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include "workers_parser.h"

#define PARAMS_AMOUNT 3
#define ERROR 1
#define SUCCESS 0
#define MAP 1
#define WORKERS 2

int main(int argc, const char *argv[]) {

    // Primero parseas el workers file creando los trabajadores correspondientes
    // Que basically son threads, y los puedo almacenar en un vector de threads se me ocurre
    // Luego, vamos a spawnear a los trabajadores
    // Segundo parseo el mapa y los voy asignando a sus colas bloqueantes que seran 3
    // A medida que voy leyendo el mapa en main.
    // Una por cada tipo de worker, aca ver el video sobre como se comportan las colas
    // Y aca va a haber que proteger al inventario porque es el recurso compartido
    // Tanto por los producers como los consumers.
    // Ademas setearemos una condition variable q no le permita a los consumers
    // Consumir, hasta que tenga los recursos que necesita para sumar 1 pto.
    // Segun la recomendacion hay q usar una sola condition variable.

    if (argc != PARAMS_AMOUNT) {
        printf("Uso: ./tp <workersfile> <mapfile>\n");
    	return ERROR;
    }

	WorkersParser workers_parser(argv[1]);
    workers_parser.read_and_create_workers();


	return SUCCESS;
}
