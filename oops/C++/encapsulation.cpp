// encapsulation is wrapping up of data and member functions in a single unit. It also implements data hiding.

// Constructor
// Special method invoked automatically at time of object creation. Used for Initialisation.
// Same name as class
// Constructor doesn't have a return type
// Only called once(automatically), at object creation
// Memory allocation happens when constructor is called

// Shallow and deep Copy
// Shallow copy: copies only the reference of the original object, but array remains same.
// Deep copy: copies the complete object, i.e. creates a brand new copy of the original object.
// when called automatically, compiler creates a shallow copy for array, for deep copy, we need to define our own copy constructor

#include <iostream>
#include <vector>

using namespace std;

class Car{
    string name;
    string color;

public:
    int *mileage;

    // Constructor
    Car(string name, string color){
        cout << "Car Constructed" << endl;
        this->name = name;
        this->color = color;
        mileage = new int; // dynamic allocation
        *mileage = 12;
    }

    Car(){  // constructor overloading -> when two or more constructors are there in a class.
        cout << "Unparametrised Car Constructor called" << endl;
    }

    // copy constructor
    Car(Car &original) {
        cout << "Car Copy Constructor called" << endl;
        name = original.name;
        color = original.color;
        // mileage = original.mileage; // shallow copy, points to the same memory address
        mileage = new int; // deep copy
        *mileage = *original.mileage;
    }

    // destructor
    ~Car(){
        cout << "Car Destroyed" << endl;
        delete mileage;
        mileage = NULL;
    }

    void start(){
        cout << "Car Started" << endl;
    }

    void stop(){
        cout << "Car Stopped" << endl;
    }

    // getter
    string getName(){
        return name;
    }
};

int main(){
    Car c1("BMW", "Black");
    cout << c1.getName() << endl;
    Car c0;
    Car c2(c1); // Copy constructor, cpp by default makes a copy constructor
    cout << c2.getName() << endl;
    cout << *c2.mileage << endl;
    *c2.mileage = 10;
    cout << *c1.mileage << endl;
    return 0;
}