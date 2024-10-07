// Koko loves to eat bananas. There are piles of bananas,
// the pile has bananas. The guards have
// gone and will come back in hours.

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int maxElement(vector<int>& arr){
    int n = arr.size();
    int maxE = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > maxE){
            maxE = max(maxE, arr[i]);
        }
    }
    return maxE;
}

int eatsBananaIn(vector<int>& arr, int hourly){
    int n = arr.size();
    int hrs = 0;
    for(int i=0; i<n; i++){
        hrs += ceil((double)arr[i]/(double)hourly);
        // hrs += ceil(arr[i]/hourly);
    }
    return hrs;
}

int minimumRate(vector<int>& arr, int h){
    int l = 1;
    int r = maxElement(arr);
    // int minRate = INT_MAX;
    while (l <= r){
        int mid = (l + r)/2;
        if(eatsBananaIn(arr, mid) <= h){
            // minRate = min(mid, minRate);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int h;
    cin >> h;

    int ans = minimumRate(arr, h);
    cout << ans;
    return 0;
}