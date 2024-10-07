// Given an array, we have found the number of occurrences of each element in the array.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    
    vector<int> hasharr(5, 0);
    for(int i=0; i<n; i++){
        hasharr[arr[i]] += 1;
    }

    int a;
    cin >> a;
    cout << hasharr[a];

    return 0;
}