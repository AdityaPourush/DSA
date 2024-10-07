#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void rotateRight(vector<int> &arr, int k){
//     vector<int> temp;
//     int s = arr.size();
//     k = k % s;

//     // storing the elements
//     for(int i = s-k; i < s; i++){
//         temp.push_back(arr[i]);
//     }

//     // shifting
//     while (s > k)
//     {
//         arr[s-1] = arr[s-k-1];
//         s--;
//     }
    

//     // adding temp elements back
//     for(int i=0; i<k; i++){
//         arr[i] = temp[i];
//     }
// }

void reverse(vector<int>& nums, int start, int end){
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(vector<int>& nums, int k){
    int s = nums.size();
    k = k%s;

    reverse(nums, s-k, s-1);
    reverse(nums, 0, s-k-1);
    reverse(nums, 0, s-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x:arr){
        cin >> x;
    }

    int k;
    cin >> k;

    rotateRight(arr, k);

    for(int &x:arr){
        cout << x << " ";
    }

    return 0;
}