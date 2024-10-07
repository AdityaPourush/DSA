//Given two decimal numbers represented by two linked
//lists Of size N and M respectively. The task is to write a
//program that returns a linked list that represents the
//sum of these two numbers.

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

void printList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int countNodes(Node* head){
    Node* curr = head;
    int s = 0;
    while (curr != nullptr)
    {
        s += 1;
        curr = curr->next;
    }
    return s;
}

int listToNum(Node* head){
    Node* curr = head;
    int s = countNodes(head);
    int i = 1;
    while (s > 1)
    {
        i = i*10;
        s -= 1;
    }
    int n = 0;
    while(curr != nullptr && i > 0){
        n = curr->data * i + n;
        curr = curr->next;
        i = i/10;
    }
    return n;
}

int sum(Node* head1, Node* head2){
    int num1 = listToNum(head1);
    int num2 = listToNum(head2);
    int sum = num1 + num2;
    return sum;
}

Node* numToList(int num) {
    Node* head = nullptr;

    while (num > 0) {
        int digit = num % 10;
        Node* newNode = new Node(digit);

        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        num /= 10;
    }

    return head;
}



int main(){
    int n;
    cin >> n;
    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    Node* head1 = new Node(arr1[0]);
    Node* curr = head1;
    for(int i=1; i<n; i++){
        curr->next = new Node(arr1[i]);
        curr = curr->next;
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    Node* head2 = new Node(arr2[0]);
    curr = head2;
    for(int i=1; i<m; i++){
        curr->next = new Node(arr2[i]);
        curr = curr->next;
    }

    int res = sum(head1, head2);
    Node* resultList = numToList(res);

    printList(resultList);
    return 0;
}