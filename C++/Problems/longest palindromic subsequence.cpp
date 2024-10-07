// Given a string s, find the longest palindromic subsequence's length in s.

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    int i=0;
    int j=n-1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
            break;
        }
        i++;
        j--;
    }
    return true;
}

int dfs(string s, string res, int i){
    int n = s.length();
    if(i == n){
        if(isPalindrome(res)){
            return res.length();
        }
        else {
            return 0;
        }
    }
    
    char curr = s[i];
    int inclMax = dfs(s, res+curr, i+1);
    int exclMax = dfs(s, res, i+1);

    return max(inclMax, exclMax);
}

int longestPalindromeSubseq(string s) {
    return dfs(s, "", 0);
}

int main(){
    string s;
    cin >> s;

    cout << longestPalindromeSubseq(s);
    return 0;
}