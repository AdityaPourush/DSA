#include <iostream>
#include <vector>

using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    int top(){
        return vec[vec.size()-1];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack s;
    
    s.push(3);
    s.push(2);
    s.push(1);

    cout << s.top();

    return 0;
}