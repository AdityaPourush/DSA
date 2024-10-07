#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void recursiveInsertionSort(vector<int> &arr, int end){
    int s = arr.size();
    if(end >= s){
        return;
    }
    int j = end;
    while(j>0 && arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
    recursiveInsertionSort(arr, end+1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    recursiveInsertionSort(arr, 0);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}