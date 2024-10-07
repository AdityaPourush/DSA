#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void allPermutations(string str, string res){
    int n = str.length();
    if(n == 0){
        cout << res << endl;
        return;
    }

    for(int i=0; i<n; i++){
        char ch = str[i];
        string newString = str.substr(0, i) + str.substr(i+1, n-i-1);
        allPermutations(newString, res+ch);  //ith character choice to add in permutation
    }
}

int main(){
    string s;
    cin >> s;
    allPermutations(s, "");

    return 0;
}