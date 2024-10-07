#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target, int low, int high){
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;
    if(nums[mid] == target){
        return mid;
    }
    else if(nums[mid] < target){
        return search(nums, target, mid+1, high);
    }
    else {
        return search(nums, target, low, mid-1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int target;
    cin >> target;

    int index = search(nums, target, 0, n-1);
    cout << index << endl;

    return 0;
}
