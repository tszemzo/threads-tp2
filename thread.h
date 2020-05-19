#ifndef THREAD_H
#define THREAD_H

#include <iostream>
#include <thread>

class Thread {
    private:
        std::thread thread;
 
    public:
        Thread() {}

        // No copiable.
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;

        Thread(Thread&& other) {
            this->thread = std::move(other.thread);
        }

        Thread& operator=(Thread&& other) {
            this->thread = std::move(other.thread);
            return *this;
        }

        /* Comienza la ejecución de la tarea definida en 'run' */
        void start() {
            thread = std::thread(&Thread::run, this);
        }

        /* Bloquea el hilo que llame a este método hasta
         * que el objeto hilo termine su ejecución. */
        void join();

        /* Indica si se le puede realizar un join al hilo */
        bool joinable();

         /* Método virtual que debe definirse en las clases que hereden de esta.
          * Representa la tarea a realizarse en la ejecución del hilo. */
        virtual void run() = 0;
        virtual ~Thread() {}
};

#endif
