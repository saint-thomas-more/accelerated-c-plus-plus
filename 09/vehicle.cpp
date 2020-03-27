#include <string>
#include <iostream>

// A Vehicle has a number of wheels and a name
class Vehicle {

public:
    int num_wheels;
    std::string name;

    Vehicle(int wheels_in, std::string name_in) {
        num_wheels = wheels_in;
        name = name_in;
    }

    virtual std::string get_sound() = 0;

    void print_summary() {
        std::cout << "name = " << name << ", wheels = " << num_wheels << ", sound = " << get_sound() << std::endl;
    }
};

class Bicycle: public Vehicle {
    public:
    Bicycle(std::string name):Vehicle(2, name){};

    std::string get_sound() override {
        return "ring! ring!";
    };
};

class Car: public Vehicle {
    public:
    std::string make;

    Car(std::string name, std::string make_in):Vehicle(4, name){
        make = make_in;
    };

    std::string get_sound() override {
        return "vroom! vroom!";
    };

    void print_summary() {
        std::cout << "make = " << make << " name = " << name << ", wheels = " << num_wheels << ", sound = " << get_sound() << std::endl;
    }
};

int main() {
    Bicycle b("Silver");
    Car c("Jet", "Ford");
    b.print_summary();
    c.print_summary();
    return 0;
}