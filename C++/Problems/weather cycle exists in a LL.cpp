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

void push_front(Node*& head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void printList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " -> " << endl;
    }
}

bool hasCycle(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle detected" << endl;
            return true;
            break;
        }
    }
    cout << "No cycle exists" << endl;
    return false;
}

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        push_front(head, val);
    }

    cout << "Linked List: " << endl;
    printList(head);


    return 0;
}