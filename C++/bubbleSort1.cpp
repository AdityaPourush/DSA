// Given an array of N integers, write a program to implement the Bubble Sorting algorithm.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=n-1; i>0; i--){
        bool swapped = false;
        for(int j=0; j<i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}