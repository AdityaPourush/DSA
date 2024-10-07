#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    // ~Node(){
    //     cout << "deleting node " << data << endl;
    //     if(next != nullptr){
    //         delete next;
    //         next = nullptr;
    //     }
    // }
};

class LinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // ~LinkedList(){
    //     cout << "deleting linked list with head" << head->data << endl;
    //     if(head != nullptr){
    //         delete head;
    //         head = nullptr;
    //     }
    // }

    ~LinkedList(){
        cout << "deleting Linked List with head " << head->data << endl;
        Node* curr = head;
        while( curr != nullptr ){
            cout << "deleting node " << curr->data << endl;
            Node* newNode = curr->next;
            delete curr;
            curr = newNode;
        }
    }

    void printLinkedList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main(){
    LinkedList ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLinkedList();

    return 0;
}