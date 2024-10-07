#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int middle, int right){
    vector<int> temp;
    int l = left;
    int m = middle+1;
    while(l <= middle && m <= right){
        if(arr[l] <= arr[m]){
            temp.push_back(arr[l]);
            l++;
        } else {
            temp.push_back(arr[m]);
            m++;
        }
    }
    while(l <= middle){
        temp.push_back(arr[l]);
        l++;
    }
    while(m <= right){
        temp.push_back(arr[m]);
        m++;
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
}

void mergeSort(vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }
    int middle = (left + right)/2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    
    merge(arr, left, middle, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}