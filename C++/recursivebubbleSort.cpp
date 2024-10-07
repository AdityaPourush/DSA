#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr, int end){
    if(end<=1){
        return;
    }
    for(int i=0; i<end-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, end-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}