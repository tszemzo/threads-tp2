#include <exception>

class ClosedQueueException : public std::exception {
public:
    const char* what() const throw() {
        return "Queue is closed";
    }
};
