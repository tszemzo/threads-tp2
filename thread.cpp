#include "thread.h"

void Thread::join() {
    thread.join();
}

bool Thread::joinable() {
    return thread.joinable();
}
