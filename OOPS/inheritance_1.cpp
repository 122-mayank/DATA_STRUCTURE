
#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    string name;

    Animal(string n) {
        name = n;
        cout << "Animal constructor is called" << endl;
    }

    void eat() {
        cout << name << " is eating" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Correct: string, not String
    Dog(string n) : Animal(n) {
        cout << "Dog constructor is called" << endl;
    }

    void bark() {
        cout << name << " is barking" << endl;
    }
};

int main() {
    // Correct: create an object directly
    Dog d("Tommy");

    d.eat();
    d.bark();

    return 0;
}
