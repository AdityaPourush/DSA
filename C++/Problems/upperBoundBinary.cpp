#include <iostream>
#include <vector>

using namespace std;

int upperBound(vector<int>& arr, int k){
    int n = arr.size();
    int ans = n;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > k){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int& num: arr){
        cin >> num;
    }
    int k;
    cin >> k;
    cout << upperBound(arr, k);

    return 0;
}