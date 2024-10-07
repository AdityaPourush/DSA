// Given an array of N integers, write a program to implement the Insertion sorting algorithm.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}