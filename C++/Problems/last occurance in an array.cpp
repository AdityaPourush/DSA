#include <iostream>
#include <vector>

using namespace std;

int findLastIndex(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,4,13,13,13,20,40};
    int target = 60;
    cout << findLastIndex(arr, target);
    return 0;
}