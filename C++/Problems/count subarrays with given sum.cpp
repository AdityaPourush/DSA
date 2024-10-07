// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
#include <bits/stdc++.h>
using namespace std;

int sumSubarray(vector<int>& nums, int k){
    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int sumSubarray(vector<int>& nums, int k){
    int n = nums.size();
    int count = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        // if(mpp.find(sum-k) != mpp.end()){
        //     count += mpp[sum-k];
        // }
        // mpp[sum]++;
        count += mpp[sum-k];
        mpp[sum]++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;

    int ans = sumSubarray(nums, k);
    cout << ans << endl;

    return 0;
}