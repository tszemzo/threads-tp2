#include "producer_thread.h"

void ProducerThread::join() {
    thread.join();
}
