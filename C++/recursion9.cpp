// fibonacci number

#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int c = fibonacci(n-1) + fibonacci(n-2);
    return c;
}

int main(){
    for(int i = 0; i < 10; i++){
        cout << fibonacci(i) << " ";
    }
    return 0;
}