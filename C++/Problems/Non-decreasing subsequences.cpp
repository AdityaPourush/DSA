// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void subsequences(vector<int>& nums, vector<int>& res, set<vector<int>>& s, int idx){
    if(res.size() >= 2){
        s.insert(res);
    }
    for(int i=idx; i<nums.size(); i++){
        if(res.empty() || nums[i] >= res.back()){
            res.push_back(nums[i]);
            subsequences(nums, res, s, i+1);
            res.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums){
    vector<int> res;
    set<vector<int>> s;
    subsequences(nums, res, s, 0);
    return vector<vector<int>>(s.begin(), s.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> ans = findSubsequences(arr);
    for(int i=0; i<n; i++){
        for(int j=0; j<ans[i].size(); i++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}