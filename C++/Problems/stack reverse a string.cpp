#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string s){
    stack<char> st;
    for(char i : s){
        st.push(i);
    }
    string resultString = "";
    while (!st.empty())
    {
        resultString+=st.top();
        st.pop();
    }
    return resultString;
}

int main(){
    string s;
    cin >> s;

    string result = reverseString(s);
    cout << result;

    return 0;
}