#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string reversePrefix(string word, char ch) {
        int index = -1;
        int s = word.length();
        for(int i=0; i<s; i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }

        if(index == -1){
            return word;
        }

        string pre = word.substr(0, index+1);
        string post = word.substr(index+1, s-index-1);

        string reverse = "";
        for(int i=index; i>=0; i--){
            // reverse.append(pre[i]);
            reverse = reverse + pre[i];
        }

        reverse.append(post);
        return reverse;
    }