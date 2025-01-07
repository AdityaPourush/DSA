#include <iostream>
#include <vector>
#include <list>

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
class Stack{
    Node<T>* head;

public:
    Stack(){
        head = nullptr;
    }

    void push(T val){
        Node<T>* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        // ll.pop_front();
        Node<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    T top(){
        // return ll.front();
        return head->data;
    }

    bool isEmpty(){
        // return ll..size() == 0;
        return head == nullptr;
    }
};

int main(){
    Stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);

    cout << s.top();

    return 0;
}