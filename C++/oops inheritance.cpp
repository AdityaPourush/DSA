#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
public:
    string color;
    void eat() {
        cout << "Eating" << endl;
    }
    void breathe() {
        cout << "Breathing" << endl;
    }
};

class Fish : public Animal {  // Fish is a child class of Animal
public:
    int fins;
    void swim() {
        cout << "Swimming" << endl;
    }
};

int main(){
    Fish f;
    f.eat();

    return 0;
}