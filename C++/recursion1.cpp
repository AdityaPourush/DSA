#include<iostream>
using namespace std;

void printNo(int n) {
    if(n<10){
        cout << n << " ";
        n++;
        printNo(n);
    }
    
}

int main() {
    int n = 0;
    printNo(n);
    return 0;
}