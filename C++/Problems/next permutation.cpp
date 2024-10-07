#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums){
    int s = nums.size();

    // finding a break point
    int brkIdx = -1;
    for(int i=s-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            brkIdx = i;
            break;
        }
    }

    // If already arranged in reverse order
    if(brkIdx == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // If it's not, then finding the least element till brkIdx and swapping it with brkIdx element
    for(int i=s-1; i>brkIdx; i--){
        if(nums[brkIdx] < nums[i]){
            swap(nums[brkIdx], nums[i]);
            break;
        }
    }

    // sorting the elements after brkIdx in increasing order
    sort(nums.begin() + brkIdx + 1, nums.end());

}

int main(){
    int s;
    cin >> s;
    vector<int> nums(s);
    for(int i=0; i<s; i++){
        cin >> nums[i];
    }

    nextPermutation(nums);
    for(int i=0; i<s; i++){
        cout << nums[i] << " ";
    }

    return 0;
}