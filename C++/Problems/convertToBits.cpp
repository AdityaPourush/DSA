#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convertToBits(int n){
    string bits = "";
    while(n != 0){
        if(n % 2 == 1){
            bits = "1" + bits;
        }
        else{
            bits = "0" + bits;
        }
        n = n / 2;
    }
    return bits;
}

int main(){
    int n;
    cin >> n;
    cout << convertToBits(n);
    return 0;
}