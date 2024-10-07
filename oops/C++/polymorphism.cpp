// Polymorphism is defined as ability of object or class to take more than one form depending on the context.
// - Compile time polymorphism
// - Run time polymorphism

#include <iostream>
#include <vector>

using namespace std;

class Print {
public:
    // function overloading
    void show(int n) {
        cout << "int: " << n << endl;
    }
    void show(string str) {
        cout << "string: " << str << endl;
    }
};

class Complex {
    int real;
    int img;
public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum(){
        cout << real << " + " << img << "i" << endl;
    }

    // operator overloading
    void operator + (Complex &obj){
        int resReal = this->real + obj.real;
        int resImg = this->img + obj.img;
        Complex c3 = Complex(resReal, resImg);
        cout << "Sum: ";
        c3.showNum();
    }

};

// function overriding
class Parent {
    public:
    void show(){
        cout << "Parent class show" << endl;
    }  
    virtual void hello(){
        cout << "Parent class hello" << endl;
    }  
};

class Child : public Parent {
    public :
    void show(){
        cout << "Child class show" << endl;
    }
    void hello(){
        cout << "Child class hello" << endl;
    }
};

int main(){
    // Print p;
    // p.show(10);
    // p.show("hello");

    // Complex c1(1,2);
    // Complex c2(3, 4);

    // c1.showNum();
    // c2.showNum();

    // c1 + c2;

    Parent p;
    Child c;
    // p.show();
    // c.show();

    Parent *ptr;
    ptr = &c;
    ptr->hello();
    return 0;
}