#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void pushAtBottom(stack<int>& s, int val){
    // base case
    if(s.empty()){
        s.push(val);
        return;
    }

    // work
    int top = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(top);
}

int main(){
    stack<int> s;
    
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 4);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}