// You are given two distinct 0-indexed integer arrays
// numsl and nums2, where numsl is a subset of
// nums2.
// For each e i < numsl.length find the
// index j such that numsl[i]
// nums2[ j ] and
// determine the next greater element of nums2[jl in
// nums2. If there is no next greater element, then the
// answer for this query is -1.
// Print an array ans of length numsl. length such
// is the next greater element as
// described above.
// The next greater element of some element x in
// an array is the first greater element that is to the
// right of x in the same array.

// Example 1:
// Input
// 3
// 4 1 2
// 4
// 1 3 4 2
// Output:
// -1 3 -1

// Example 2:
// Input:
// 2
// 2 4
// 4
// 1 2 3 4
// Output:
// 3 -1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ifNextBigExists(vector<int>& arr1, vector<int>& arr2){
    int s = arr1.size();
    int t = arr2.size();
    bool flag = false;
    vector<int> res;
    for(int i=0 ;i<s; i++){
        flag = false;
        int k = arr1[i];
        for(int j=0; j<t; j++){
            if(arr2[j] == k){
                for(int l=j; l<t; l++){
                    if(arr2[l] > arr2[j]){
                        res.push_back(arr2[l]);
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(!flag){
            res.push_back(-1);
        }
    }
        return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    vector<int> res = ifNextBigExists(arr1, arr2);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}