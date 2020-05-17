#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

// Template de una cola bloqueante, la cual bloquea la actividad del thread en
// el pop en el caso que la cola esté vacía, utilizando conditional variables.
template <typename T> class BlockingQueue {
private:
    bool isClosed;
    std::mutex m;
    std::condition_variable cv;
    std::queue<T> queue;

public:
    BlockingQueue(): isClosed(false) {}

    void push(T value) {
        std::unique_lock<std::mutex> lk(m);
        queue.push(value);
        cv.notify_all();
    }

    T pop() {
        std::unique_lock<std::mutex> lk(m);

        while (queue.empty()) {
            if (isClosed) {
                std::cout << "La cola esta cerrada";
                // Aca mete la excepcion
                return;
            }
            
            cv.wait(lk);
        }
        
        T t = queue.front();
        queue.pop();
        return t;
    }

    size_t size(){
        return queue.size();
    }

    void close() {
        std::unique_lock<std::mutex> lk(m);
        isClosed = true;
        cv.notify_all();
    }

    ~BlockingQueue() {}
};

#endif