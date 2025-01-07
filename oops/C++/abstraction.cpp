#include <iostream>
#include <vector>

using namespace std;

// abstract class
class Shape{
    public:
        virtual void draw() = 0; // abstract function, pure virtual function: that's the only thing that identifies an abstract class in cpp
};

class Circle : public Shape{
public:
    void draw(){
        cout << "draw Circle\n";
    }
};

class Square : public Shape{
public:
    void draw(){
        cout << "draw Square\n";
    }
};

int main(){
    Circle c1;
    c1.draw();
    Square s1;
    s1.draw();
    
    return 0;
}