// print linearly from 1 to n

// 1st Way
#include<iostream>
using namespace std;

void printToN(int i, int n){
    if(i<=n){
        cout << i << "\n";
        printToN(i+1,n);
    }
}

// 2nd Way
void printTon(int n){
    if(n==1){
        cout << n;
    } else {
        printTon(n-1);
        cout << n;
    }
}

void prToN(int n){
    if(n>0){
        prToN(n-1);
        cout << n;
    }
}

int main(){

    int a;
    cout << "Enter a number";
    cin >> a;
    printToN(1, a);
    printTon(a);

    return 0;
}