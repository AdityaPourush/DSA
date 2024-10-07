#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int>& arr, int k){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    int ans = n;

    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] >= k){
            ans = mid;
            right = mid-1;
        }
        else if(arr[mid] < k){
            left = mid + 1;
        }
    }
    return ans;
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
    cout << lowerBound(arr, k);

    return 0;
}