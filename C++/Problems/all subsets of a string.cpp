// if n elements are there => no. of total subsets = 2^n

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void allSubsets(string str, string subset){
    int n = str.length();
    if(n == 0){
        cout << subset << endl;
        return;
    }
    allSubsets(str.substr(1, n-1), subset + str[0]);
    allSubsets(str.substr(1, n-1), subset);
}

int main(){
    string str;
    cin >> str;
    allSubsets(str, "");

    return 0;
}