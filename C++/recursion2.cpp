// print something n times
#include<iostream>
using namespace std;

void printName(int i,int n){
    if(i > n){
        return;
    } else {
        cout << "You" << "\n";
        printName(i+1, n);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printName(1,n);
}