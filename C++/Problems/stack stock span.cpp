#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpan(vector<int> arr){
    int n = arr.size();
    vector<int> res(n, 0);
    stack<int> st;

    for(int i=0; i<n; i++){
        int curr = arr[i];
        while(!st.empty() && arr[st.top()] <= curr){
            st.pop();
        }
        if(st.empty()){
            res[i] = i+1;
        }
        else {
            res[i] = i - st.top();
        }
        st.push(i);
    }
    return res;
}

int main(){
    vector<int> arr = {};

    vector<int> ans = stockSpan(arr);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}