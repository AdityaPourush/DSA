#include <iostream>
#include <vector>

using namespace std;

void indexsOfKey(vector<int> nums, int key, int n){
    int s = nums.size();
    if(n == s){
        return;
    }
    if(nums[n] == key){
        cout << n << " ";
    }
    indexsOfKey(nums, key, n+1);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int key;
    cin >> key;

    indexsOfKey(nums, key, 0);

    return 0;
}