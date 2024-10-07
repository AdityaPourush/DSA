// To print from n to 1
#include<iostream>
using namespace std;

void reverseToN(int n){
    if(n>0){
        cout << n;
        reverseToN(n-1);
    }
}

int main(){
    int a;
    cin >> a;
    reverseToN(a);

    return 0;
}