// Given string num representing a non-negative
// integer num, and an integer k, write a program to
// return the smallest possible integer after removing
// k digits from num.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string removeKdigits(string num, int k){
    int n = num.length();
    if(n == k) return "0";  // handling special case for empty string.

    string res;
    for(char digit : num){
        while(k > 0 && !res.empty() && res.back() > digit){
            res.pop_back();
            k--;
        }
        res.push_back(digit);
    }

    while(k > 0){
        res.pop_back();
        k--;
    }

    // remove leading zeros
    int start = 0;
    int res_length = res.length();
    while(start < res_length-1 && res[start] == 0){
        start++;
    }

    return res.substr(start);
}

int main(){
    string n;
    cout << "Enter the number: ";
    cin >> n;

    int k;
    cout << "Digits to be removed: ";
    cin >> k;

    string result = removeKdigits(n, k);
    cout << "After removal the digit is: " << result;

    return 0;
}