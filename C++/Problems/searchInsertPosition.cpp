#include <iostream>
#include <vector>

using namespace std;

int searchInsertPosition(vector<int>& arr, int k){
    int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i:arr){
        cin >> i;
    } 
    int k;
    cin >> k;
    cout << searchInsertPosition(arr, k);

    return 0;
}