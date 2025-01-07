#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool duplicateParanthesis(string &expr)
{
    // Write your code here
    int n = expr.length();
    stack<char> st;
    for(int i=0; i<n; i++){
        if(expr[i] != ')'){
            st.push(expr[i]);
        }
        else {
            if(st.top() == '('){
                return true;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string expr = "(a+(b+c))";
    cout << duplicateParanthesis(expr);
    return 0;
}