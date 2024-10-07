#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool linearSearch(vector<int>& arr, int num){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    int maxCount = 1;
    for(int i=0; i<n; i++){
        int currCount = 1;
        int req = nums[i];
        while(linearSearch(nums, req+1)){
            req++;
            currCount++;
        }
        maxCount = max(maxCount, currCount);
    }
    return maxCount;
}

int longestConsecutive2(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxCount = 1;
    int lstSmaller = INT_MIN;
    int currCount = 0;
    
    for(int i=0; i<n; i++){
        if(nums[i] == lstSmaller + 1){
            currCount += 1;
            lstSmaller = nums[i];
        }
        else if (nums[i] != lstSmaller) {
            lstSmaller = nums[i];
            currCount = 1;
        }
        maxCount = max(maxCount, currCount);
    }
    return maxCount;
}

int longestConsecutive3(vector<int>& nums){
    int n = nums.size();
    int maxCount = 1;
    set<int> stt;
    for(int i=0; i<n; i++){
        stt.insert(nums[i]);
    }

    for(auto it:stt){
        if(stt.find(it-1) == stt.end()){
            int currCount = 1;
            int x = it;
            while(stt.find(x+1) != stt.end()){
                currCount++;
                x++;
            }
            maxCount = max(maxCount, currCount);
        }
    }
    return maxCount;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int ans = longestConsecutive3(nums);
    cout << ans;

    return 0;
}