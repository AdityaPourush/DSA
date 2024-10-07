#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int>& nums){
    int n = nums.size();
    int maxP = INT_MIN;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(nums[j] - nums[i] > maxP){
                maxP = nums[j] - nums[i];
            }
        }
    }
    return maxP;
}

int maxProfitOptimal(vector<int>& prices){
    int n = prices.size();
    int maxP = 0;
    int minPrice = prices[0];
    for(int i=1; i<n; i++){
        if(prices[i] <= minPrice){
            minPrice = prices[i];
        } else {
            int diff = prices[i] - minPrice;
            maxP = max(maxP, diff);
        }
    }
    return maxP;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = maxProfitOptimal(arr);
    cout << ans;
    return 0;
}