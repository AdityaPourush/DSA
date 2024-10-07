#include <iostream>
#include <vector>

using namespace std;

string digitToWord(int n){
    switch(n){
        case 0 : return "zero";
        case 1 : return "one";
        case 2 : return "two";
        case 3 : return "three";
        case 4 : return "four";
        case 5 : return "five";
        case 6 : return "six";
        case 7 : return "seven";
        case 8 : return "eight";
        case 9 : return "nine";
        default: return "";
    }
}

string numToWords(int n){
    if(n < 10){
        return digitToWord(n);
    }
    return numToWords(n/10)+ " " + numToWords(n%10);
}

int main(){
    int n;
    cin >> n;
    cout << numToWords(n);

    return 0;
}