#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void allsubSequences(string s, string res, int i, vector<string>& ans){
    if(i >= s.length()){
        if(res.length() != 0){
            ans.push_back(res);
        }
        return;
    }
    allsubSequences(s, res+s[i], i+1, ans);
    allsubSequences(s, res, i+1, ans);
}

int main() {
    string s;
    cin >> s;
    vector<string> ans;
    allsubSequences(s, "", 0, ans);
    sort(ans.begin(), ans.end());
    for(string i : ans){
            cout << i << " ";
    }
}