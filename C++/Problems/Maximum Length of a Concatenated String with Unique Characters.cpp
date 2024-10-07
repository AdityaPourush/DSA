#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

int maxCount(vector<string>& arr, int index, string subSequence){
    int n = arr.size();
    // base case
    if(index >= n){
        unordered_set<char> seti;
        int l = subSequence.length();
        for(int i=0; i<l; i++){
            if(seti.find(subSequence[i]) != seti.end()){
                return 0;
            }
            seti.insert(subSequence[i]);
        } 
        return l;
    }

    // function work
    int includeCount = maxCount(arr, index+1, subSequence+arr[index]);

    int excludeCount = maxCount(arr, index+1, subSequence);

    int maxi = max(includeCount, excludeCount);
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = maxCount(arr, 0, "");
    cout << ans;
    return 0;
}