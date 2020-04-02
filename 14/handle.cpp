// A handle is a value that refers to an object

#include <iostream>
#include <string>

using namespace std;

template <class T> class Handle{

    // p is a pointer to a type T
    private:
    T* p;

    public:

    // Default constructor, initialise pointer to 0
    Handle(): p(0){}

    Handle(T* t):p(t){};

    // Copy constructor
    Handle(const Handle& s) : p(0) {
        // If we can cast the input to our pointer type we clone it
        if((s.p)) {
            p = s.p -> clone();
        }
    }

    // Overload = operator
    Handle<T>& operator=(const Handle& rhs) {
        // If the new value is not the same
        if(&rhs != this) {
            // Free the currently managed data
            delete p;
            // Set p to the new p, or 0 if it doesn't exist
            p = rhs.p ? ((rhs.p).clone()):0;
        }
        // Return the current object
        return *this;       
    }

    // Destructor
    ~Handle() {
        delete p;
    }

    // Casting to boolean results in the pointer
    operator bool() const {
        return p;
    }

    T& operator*() const {
        if(p) {
            return *p;
        }
    }

    T* operator->() const {
        if(p) {
            return p;
        }
    }
};

int main() {
    int* a = new int(5);
    Handle<int> handle_a(a);

    cout << *handle_a << endl;
}