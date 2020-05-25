#include "blocking_queue.h"
#include "exceptions.h"

void BlockingQueue::push(char value) {
    std::unique_lock<std::mutex> lk(m);
    queue.push(value);
    cv.notify_all();
}

char BlockingQueue::pop() {
    std::unique_lock<std::mutex> lk(m);
    while (queue.empty()) {
        if (isClosed) {
            throw ClosedQueueException();
        }
        cv.wait(lk);
    }
    
    char t = queue.front();
    queue.pop();
    return t;
}

size_t BlockingQueue::size(){
    return queue.size();
}

void BlockingQueue::close() {
    std::unique_lock<std::mutex> lk(m);
    isClosed = true;
    cv.notify_all();
}
