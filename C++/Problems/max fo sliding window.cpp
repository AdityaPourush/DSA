#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void printMaxSlidingWindow(vector<int> &arr, int k){
    int i=0;
    int s = arr.size();
    while(i < s-k+1){
        int maxi = arr[i];
        for(int j=1; j<k; j++){
            maxi = max(maxi, arr[i+j]);
        }
        cout << maxi << " ";
        i++;
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

    printMaxSlidingWindow(arr, k);

    return 0;
}