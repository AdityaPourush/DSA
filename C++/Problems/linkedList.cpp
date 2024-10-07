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
};

void printLinkedList(Node* head){
    Node* curr = head;
    while(curr!=nullptr){
        cout << curr->data << "->";
        curr = curr->next;
    }
}

void push_front(Node*& head, int val){       // remember to pass by reference i.e. Node*& head
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void push_back(Node*& head, int val){
    Node* newNode = new Node(val);
    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    push_front(head, 0);
    push_back(head, 5);
    printLinkedList(head);
    return 0;
}