//  Given an array of N integers, write a program to implement the Selection sorting algorithm.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int k = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = k;
        // swap(arr[i], arr[minIndex]);
    }
    
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}