#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxLen(vector<int>& nums){
    int n = nums.size();
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == 0){
            int len = i+1;
            maxLen = max(maxLen, len);
        }
        else {
            if(mpp.find(sum) != mpp.end()){
                int len = i - mpp[sum];
                maxLen = max(maxLen, len);
            }
            else {
                mpp[sum] = i;
            }
        }
    }
    return maxLen;
}

int main(){
    int n;
    cin>> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int ans = maxLen(nums);
    cout << ans;

    return 0;
}