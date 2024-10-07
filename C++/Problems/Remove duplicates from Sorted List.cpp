#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* deleteDuplicates(Node* head) {
        Node* curr = head;
        Node* itr = head->next;
        while(itr != nullptr){
            if(itr->data != curr->data){
                curr->next = itr;
                curr = curr->next;
                itr = itr->next;
            } else {
                itr = itr->next;
            }
        }
        curr->next = nullptr;
        return head;
    }

void printList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i: arr) cin >> i;
    
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    Node* res = deleteDuplicates(head);
    printList(res);

    return 0;
}