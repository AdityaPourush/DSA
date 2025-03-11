#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>
class Queue{
private:
    stack<T> stack1;
    stack<T> stack2;

public:
    void push(T val){
        stack1.push(val);
        cout << "enqueued: " << val << endl;
    }

    void pop(){
        if(stack1.empty() && stack2.empty()){
            cout << "The Queue is empty.." << endl;
        }

        if(stack2.empty()){
            while(!stack1.empty()){
                T topElement = stack1.top();
                stack2.push(topElement);
                stack1.pop();
            }
        }

        stack2.pop();
    }

    T front(){
        if(stack1.empty() && stack2.empty()){
            cout << "The Queue is empty.." << endl;
        }

        if(stack2.empty()){
            while(!stack1.empty()){
                T topElement = stack1.top();
                stack2.push(topElement);
                stack1.pop();
            }
        }

        return stack2.top();
    }

    bool empty(){
        return stack1.empty() && stack2.empty();
    }
};

int main(){
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}