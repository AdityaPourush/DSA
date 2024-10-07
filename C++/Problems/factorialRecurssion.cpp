// generate factorial using recurssion

#include <iostream>
#include <vector>
using namespace std;

int factorial(int num){
    if(num == 1){
        return 1;
    }
    return num * factorial(num-1);
}

int main(){
    int n;
    cin >> n;
    int factorialOfN = factorial(n);
    cout << factorialOfN;
    return 0;
}