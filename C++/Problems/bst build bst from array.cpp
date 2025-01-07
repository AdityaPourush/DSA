#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertInBst(int num, Node* root){
    if(root == nullptr){
        root = new Node(num);
        return root;
    }
    if(num < root->data){
        root->left = insertInBst(num, root->left);
    }
    if(num > root->data){
        root->right = insertInBst(num, root->right);
    }
    return root;
}

Node* buildBst(vector<int> arr){
    int n = arr.size();
    Node* root = nullptr;

    for(int i=0; i<n; i++){
        root = insertInBst(arr[i], root);
    }

    return root;
}

void inOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main(){
    vector<int> nums = {3, 6, 7, 2, 8, 11, 5};
    Node* root = buildBst(nums);
    inOrderTraversal(root);

    return 0;
}