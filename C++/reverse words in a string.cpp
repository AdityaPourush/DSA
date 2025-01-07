#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    int n = s.size();
    vector<string> words;
    string word = "";
    for(int i=0; i<n; i++){
        if(s[i] == ' ' && word.length() > 0){
            words.push_back(word);
            word = "";
        }
        else if(s[i] != ' ') {
            word += s[i];
        }
    }
    if(word.length() > 0) words.push_back(word);
    string sen = "";
    int m = words.size();
    for(int i=m-1; i>=0; i--){
        sen = sen + words[i];
        if(i != 0) sen += " ";
    }
    // for(auto& i : words){
    //     cout << i << " ";
    // }
    return sen;
}

int main(){
    string s;
    getline(cin, s);
    string ans = reverseWords(s);
    cout << ans;

    return 0;
}