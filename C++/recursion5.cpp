// Sum of first N numbers
#include <iostream>
using namespace std;

int sumToN(int n){
    if(n < 1){
        return 0;
    }
    return n + sumToN(n-1);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << sumToN(n);
}
