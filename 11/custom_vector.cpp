#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;


template <class T> class Custom_Vector {
    public:

    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;

    // Default constructor
    Custom_Vector() {
        create();
    }

    // Initialise with size of n, using value t
    explicit Custom_Vector(size_type n, const T& t = T()) {
        create(n, t);
    }

    // Copy constructor
    Custom_Vector(const Custom_Vector& input) {
        create(input.begin(), input.end());
    }

    // Destructor
    ~Custom_Vector() {
        uncreate();
    }

    // Be able to use the [] operator to refer to an element of the Custom_Vector
    T& operator[](size_type i) {
        return data[i];
    }

    const T& operator[](size_type i) const {
        return data[i];
    }

    // Assignment operator (=)
    Custom_Vector<T>& operator=(const Custom_Vector& input) {
         // check for self-assignment
         if (&input != this) {
             // free the array in the left-hand side
             uncreate();
             // copy elements from the right-hand to the left-hand side
             create(input.begin(), input.end());
             }
             return *this;
    }

    // Get the size of the Custom_Vector
    size_type const size(){
        return last_used - data;
    }

    iterator begin() {
        return data;
    }

    iterator end() {
        return last_used;
    }

    const_iterator begin() const {
        return data;
    }

    const_iterator end() const {
        return last_used;
    }

    // Push an element to the back of the vector
    void push_back(const T& t) {
        // If we have no more space then we need to grow
        if(avail == last_used) {
            grow();
        }
        unchecked_append(t);
    }

    // Remove an individual element from the vector via an index
    void erase(size_type remove_index) {
        if(remove_index >= size()) {
            throw range_error("Index out of range");
        }
        if(size() == 1) {
            clear();
        }

        iterator current_pointer = &data[remove_index];

        // We move all elements back one
        while(current_pointer + 1 != last_used) {
            T next_value = *(current_pointer + 1);
            *current_pointer = next_value;
            current_pointer++;
        }
        last_used--;
    }

    // Completely clear the vector of all elements
    void clear() {
        uncreate();
    }

    void print() {
        for(iterator i = data; i < last_used; i++) {
            cout << *i << " | ";
        }
        cout << "|" << endl;
    }

    private:
    // First pointer
    iterator data;
    // One past the last used element
    iterator last_used;
    // One past the last available element
    iterator avail;

    std::allocator<T> alloc;

    void create() {
        data = last_used = avail = 0;
    }

    void create(size_type n, const T& t) {
        data = alloc.allocate(n);
        last_used = avail = data + n;;
        uninitialized_fill(data, last_used, t);
    }

    void create(const_iterator begin, const_iterator end) {
        data = alloc.allocate(end - begin);
        last_used = avail = uninitialized_copy(begin, end, data);
    }

    void uncreate() {
        if (data) {
            // destroy (in reverse order) the elements that were constructed
            iterator it = avail;
            while (it != data) {
                alloc.destroy(--it);
            }
            // return all the space that was allocated
            alloc.deallocate(data, avail - data);
        }
        // reset pointers to indicate that the Vec is empty again
        data = last_used = avail = 0;
    }

    void grow() {
        size_type new_size = max(2 * (avail - data), ptrdiff_t(1));
        iterator new_data = alloc.allocate(new_size);
        iterator new_last = uninitialized_copy(data, last_used, new_data);

        uncreate();
        data = new_data;
        last_used = new_last;
        avail = data + new_size;
    }

    void unchecked_append(const T& t) {
        alloc.construct(last_used++, t);
    }
};

int main() {
    Custom_Vector<int> integers;
    integers.push_back(5);
    integers.push_back(3);
    integers.push_back(4);
    cout << "Original: ";
    integers.print();

    cout << "Remove elements at the front: ";
    integers.erase(0);
    integers.erase(0);

    Custom_Vector<int> integers_copy = integers;
    integers_copy.push_back(6);

    integers.print();

    cout << "Copy and add 6: ";
    integers_copy.print();

    cout << "Clear the copy: ";
    integers_copy.clear();
    integers_copy.print();
}