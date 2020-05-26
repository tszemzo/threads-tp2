#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

// Clase de la cola bloqueante, la cual bloquea la actividad del thread en
// el pop en el caso que la cola esté vacía, utilizando conditional variables.
class BlockingQueue {
private:
    bool isClosed;
    std::mutex m;
    std::condition_variable cv;
    std::queue<char> queue;

public:
    BlockingQueue(): isClosed(false) {}

    void push(char value);

    char pop();

    void close();

    ~BlockingQueue() {}
};

#endif
