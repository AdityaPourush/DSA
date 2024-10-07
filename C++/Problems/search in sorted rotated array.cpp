#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& arr, int target, int start, int end){
    if(start > end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] >= arr[start]){
        if(arr[mid] >= target && arr[start] <= target){
            return search(arr, target, start, mid-1);
        }
        else {
            return search(arr, target, mid+1, end);
        }
    }
    else {
        if(arr[mid] <= target && arr[end] >= target){
            return search(arr, target, mid+1, end);
        }
        else {
            return search(arr, target, start, mid-1);
        }

    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << search(arr, k, 0, n-1);

    return 0;
}