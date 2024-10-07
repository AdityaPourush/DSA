#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
    void eat(){
        cout << "eats\n";
    }

    void breathe(){
        cout << "breathes\n";
    }
};

class Mammal : public Animal{
public:
    string bloodType;
    Mammal(){
        bloodType = "warm";
    }
};

class Dog : public Mammal{
    public:
    void tailWag(){
        cout << "Dog wags tail\n";
    }
};

int main(){
    Dog d1;
    d1.eat();
    cout << d1.bloodType << endl;
    d1.breathe();
    d1.tailWag();

    return 0;
}