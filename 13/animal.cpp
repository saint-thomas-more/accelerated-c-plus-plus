#include <string>
#include <iostream>

using namespace std;

class Animal {
    protected:
    string name;

    public:
    Animal(){};

    Animal(string n) {
        name = n;
    }

    virtual void make_noise() = 0;
};

class Cat : public Animal {

    private:
    string pet_name;

    public:
    friend void change_name(Cat& c, string new_name);

    static int num_cats;
    Cat(){
        name = "Cat";
        pet_name = "Unknown";
        Cat::num_cats++;
    }

    Cat(string pet_name_in) : Cat() {
        pet_name = pet_name_in;
    }

    void make_noise() {
        cout << "Meow! from a " << name << ", nicknamed " << pet_name << endl;
    }

    static int get_total_cats() {
        return num_cats;
    }
};

void change_name(Cat& c, string new_name) {
    c.pet_name = new_name;
}

int Cat::num_cats = 0;

int main() {
    Cat c("Fluffy");
    change_name(c, "Mr. Bobbles");
    c.make_noise();

    Cat* d = new Cat();
    d->make_noise();
    delete d;

    cout << "There are " << c.get_total_cats() << " total cats" << endl;
}