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

Node* OddEvenList(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(odd->next && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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

    Node* res = OddEvenList(head);
    printList(res);

    return 0;
}