#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void pushAtBottom(stack<int>& s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(top);
}

void reverseStack(stack<int>& s){
    // base case
    if(s.empty()){
        return;
    }

    int top = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, top);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }    

    return 0;
}