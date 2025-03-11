#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(T val){
        this->data = val;
        this->next = nullptr;
    }
};

template <class T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
public:
    Queue(){
        head = tail = nullptr;
    }

    void push(T val){
        Node<T>* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T front(){
        return head->data;
    }

    bool isempty(){
        return head == nullptr;
    }
};

int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.isempty()){
        cout << q.front() << endl;
        q.pop();
    }
    

    return 0;
}