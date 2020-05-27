#ifndef THREAD_H
#define THREAD_H

#include <utility>
#include <iostream>
#include <thread>
#include <string>

class ProducerThread {
    private:
        std::thread thread;
 
    public:
        ProducerThread() {}

        // No copiable.
        ProducerThread(const ProducerThread&) = delete;
        ProducerThread& operator=(const ProducerThread&) = delete;

        ProducerThread(ProducerThread&& other) {
            this->thread = std::move(other.thread);
        }

        ProducerThread& operator=(ProducerThread&& other) {
            this->thread = std::move(other.thread);
            return *this;
        }

        /* Comienza la ejecución de la tarea definida en 'run' */
        void start() {
            thread = std::thread(&ProducerThread::run, this);
        }

        /* Bloquea el hilo que llame a este método hasta
         * que el objeto hilo termine su ejecución. */
        void join();

         /* Método virtual que debe definirse en las clases que hereden de esta.
          * Representa la tarea a realizarse en la ejecución del hilo. */
        virtual void run() = 0;

        virtual ~ProducerThread() {}
};

#endif
