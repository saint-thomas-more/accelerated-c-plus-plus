// This gives a demonstration of various copy and move semantics

#include <iostream>
#include <string>

// We define a basic class which wraps an integer array
class NaiveHolder
{
    public:

    NaiveHolder(int size)
    {
        m_data = new int[size];
        m_size = size;
        std::cout << "Constructed NaiveHolder" << std::endl;
    }

    ~NaiveHolder()
    {
        std::cout << "Destroyed NaiveHolder" << std::endl;
        delete[] m_data;
    }

    void PrintAddress() {
        std::cout << m_data << std::endl;
    }

  private:

    int* m_data;
    size_t m_size;
};

class BetterHolder
{
    public:

    BetterHolder(){};

    BetterHolder(int size)
    {
        m_data = new int[size];
        m_size = size;
        std::cout << "Constructed BetterHolder" << std::endl;
    }

    ~BetterHolder()
    {
        std::cout << "Destroyed BetterHolder" << std::endl;
        delete[] m_data;
    }

    // Define copy constructor
    BetterHolder(const BetterHolder& h) {
        std::cout << "Constructed BetterHolder via copy constructor" << std::endl;
        m_size = h.m_size;
        m_data = new int[m_size];
        for(auto i = 0; i < m_size; ++i) {
            m_data[i] = h.m_data[i];
        }
    }

    // Define move constructor, which takes an r-value
    // then just moves the contents of h into the current object
    BetterHolder(BetterHolder&& h) {
        m_size = h.m_size;
        m_data = h.m_data;
        // Remove references to the r-value
        h.m_data = nullptr;
        h.m_size = 0;
    }

    // Define the copy assigment operator, which performs a deep copy
    BetterHolder& operator=(const BetterHolder& h) {
        std::cout << "Constructed BetterHolder via copy assignment" << std::endl;
        if(this == &h) {
            return *this;
        }
        delete[] m_data;

        m_size = h.m_size;
        m_data = new int[h.m_size];
        std::copy(h.m_data, h.m_data + h.m_size, m_data);
        return *this;
    }

    // Define the move assignment operator, which takes an r-value
    BetterHolder& operator=(BetterHolder&& h) {
        std::cout << "Constructed BetterHolder via move assignment" << std::endl;
        if(this == &h) {
            return *this;
        }
        // Remove our current data
        delete[] m_data;
        // Copy the data sources
        m_size = h.m_size;
        m_data = h.m_data;
        
        h.m_data = nullptr;
        h.m_size = 0;

        return *this;
    }

  private:

    int* m_data;
    size_t m_size;
};

BetterHolder GetBetterHolderHundred() {
    return BetterHolder(100);
}

void DemonstrateNaiveHolders() {
    // Using NaiveHolders a shallow copy is done, the pointers point to the same data
    // The destructors are also called twice
    NaiveHolder a(15);
    NaiveHolder b = a;
}

void DemonstrateBetterHolders() {
    // Better holders use the copy constructor/operators
    BetterHolder a(15); // Normal
    BetterHolder b(a); // Copy constructor
    BetterHolder c = b; // Copy constructor
    c = a; // Copy assignment

    // Move assignment
    c = GetBetterHolderHundred();
}

int main() {
    // DemonstrateNaiveHolders();
    DemonstrateBetterHolders();
    return 0;
}