// When properties and member functions of base class are passed on to the derived class.

// base / super / parent class
// derived / sub / child class

// inheritance is used for code re-usability

#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
    string color;

    void eat(){
        cout << "eats\n";
    }

    void breathe(){
        cout << "breathes\n";
    }

protected:
    void move(){
        cout << "moves\n";
    }
};

// Fish is a child class of Animal
// by default inheritance is public.
class Fish : public Animal{ // inheritance happening
    public:
    int fins;

    void swim(){
        move();
        cout << "swims\n";
    }
};

int main(){
    Fish f1;
    f1.fins = 3;
    f1.eat();  // inherited from parent class.
    cout << f1.fins << endl;
    f1.swim();

    return 0;
}