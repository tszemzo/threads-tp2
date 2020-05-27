#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

// Clase que modela la cola bloqueante, la cual bloquea la actividad del thread
// en el pop en caso que la cola esté vacía, utilizando condition variables.
class BlockingQueue {
private:
    bool isClosed;
    std::mutex m;
    std::condition_variable cv;
    std::queue<char> queue;

public:
	/*Constructor de la clase.*/
    BlockingQueue(): isClosed(false) {}

    /* Guarda un elemento en la cola avisandole a los
     * threads que se encuentran en espera en caso de
     * que los haya.
     */
    void push(char value);

    /* Saca un elemento de la cola en caso de ser posible.
     * Si no hay elementos, mediante una condition variable
     * hace esperar a los threads bloqueandolos.
     */
    char pop();

    /*Cierra la cola bloqueante notificando a todos los threads que esperan.*/
    void close();

    /*Destructor de la clase.*/
    ~BlockingQueue() {}
};

#endif
