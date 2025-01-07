#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1; i>= 0; i--){
        int curr = nums[i];
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr = {5,7,1,7,6,0};
    vector<int> res = nextGreaterElement(arr);
    for(int i=0; i<arr.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}