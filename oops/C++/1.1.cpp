#include <iostream>
#include <vector>

using namespace std;

class Student{
    // properties
    string name;
    float marks;

    // methods
public:
    void getpercentage(){
        cout << marks << endl;
    }

    //setters
    void setName(string nameVal){
        name = nameVal;
    }
    void setMarks(float marksVal){
        marks = marksVal;
    }

    //getters
    string getName(){
        return name;
    }
    float getMarks(){
        return marks;
    }
};

int main(){
    Student s1; // object declaration
    cout << sizeof(s1) << endl; // size of object in bytes on stack
    s1.setName("Anil");
    s1.setMarks(100);
    cout << s1.getName() << " " << s1.getMarks() << endl;
}