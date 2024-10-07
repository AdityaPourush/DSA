#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums) {
        int s = nums.size();
        int j = -1;
        for(int i=0; i<s; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
        for(int i=j+1; i<s; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
}

// void moveZeroes(vector<int>& nums) {
//         vector<int> temp;
//         int s = nums.size();
//         for(int i=0; i<s; i++){
//             if(nums[i] != 0){
//                 temp.push_back(nums[i]);
//             }
//         }
//         int t = temp.size();
//         for(int i=0; i<t; i++){
//             nums[i] = temp[i];
//         }
//         for(int i=t; i<s; i++){
//             nums[i] = 0;
//         }
// }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &x:nums){
        cin >> x;
    }

    moveZeroes(nums);

    for(int &x:nums){
        cout << x << " ";
    }
}