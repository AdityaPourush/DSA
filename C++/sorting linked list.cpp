#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int countNodes(Node* head){
    Node* curr = head;
    int n = 0;
    while(curr != nullptr){
        n+=1;
        curr = curr->next;
    }
    return n;
}

void sort(Node* head){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    int n = countNodes(head);
    Node* curr;
    for(int i=0; i<n-1; i++){
        curr = head;
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(curr->data > curr->next->data){
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr=curr->next;
        }
        if(!swapped){
            break;
        }
    }
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
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    sort(head);
    printList(head);

    return 0;
}