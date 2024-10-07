#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& arr){
    map<int, int> mpp;
    int n = arr.size();

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
        if(n%2 == 0){
            if(mpp[arr[i]] >= n/2){
                return arr[i];
            }
        } else {
            if(mpp[arr[i]] >= (n/2)+1){
                return arr[i];
            }
        }
    }
    return -1;
}

// Using Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int el;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(cnt == 0){
            el = nums[i];
            cnt++;
        }
        else if(el == nums[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    return el;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = majorityElement(arr);
    cout << ans;
    return 0;
}