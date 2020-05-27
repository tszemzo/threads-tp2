#include <exception>

/* Excepcion lanzada cuando la cola bloqueante se
 * encuentra cerrada.
 */
class ClosedQueueException : public std::exception {
public:
    const char* what() const throw() {
        return "Queue is closed";
    }
};

/* Excepcion lanzada cuando no hay mas recursos en el
 * inventario.
 */
class NoMoreResourcesException : public std::exception {
public:
    const char* what() const throw() {
        return "No more resources";
    }
};
