#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class Stack {
private:
    queue<T> q1;
    queue<T> q2;

public:
    void push(T val) {
        q1.push(val);
        cout << "pushed: " << val << endl;
    }

    void pop() {
        if(q1.empty()) {
            cout << "The Stack is empty.." << endl;
            return;
        }

        while(q1.size() > 1) {
            T frontElement = q1.front();
            q2.push(frontElement);
            q1.pop();
        }

        // T topElement = q1.front();
        q1.pop();
        swap(q1, q2);
        // cout << "popped: " << topElement << endl;
    }

    T top(){
        if(q1.empty()) {
            cout << "The Stack is empty.." << endl;
        }

        while(q1.size() > 1) {
            T frontElement = q1.front();
            q2.push(frontElement);
            q1.pop();
        }

        T topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main(){
    Stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}