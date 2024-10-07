#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int s = nums.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;

    for(int i=0; i<s; i++){
        if(nums[i] > 0){
            pos.push_back(nums[i]);
        }
        else if(nums[i] < 0){
            neg.push_back(nums[i]);
        }
    }
    for(int i=0; i<pos.size(); i++){
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }

    return ans;
}

vector<int> rearrangeArray(vector<int>& nums) {
    int s = nums.size();
    vector<int> ans(s);
    int posPtr = 0;
    int negPtr = 1;
    for(int i=0; i<s; i++){
        if(nums[i] > 0){
            ans[posPtr] = nums[i];
            posPtr+=2;
        }
        else{
            ans[negPtr] = nums[i];
            negPtr+=2;
        }
    }
    return ans;
}

int main(){
    int s;
    cin >> s;
    vector<int> nums(s);
    for(int i=0; i<s; i++){
        cin >> nums[i];
    }
    vector<int> ans = rearrangeArray(nums);

    for(int i=0; i<s; i++){
        cout << ans[i] << " ";
    }

    return 0;
}