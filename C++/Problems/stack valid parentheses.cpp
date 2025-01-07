#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s){
    int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            if (curr == '(' || curr == '{' || curr == '[') {
                st.push(curr);
            }
            if (curr == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
            if (curr == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
            if (curr == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
}

int main(){
    string sample = "]";
    cout << isValid(sample);
    return 0;
}