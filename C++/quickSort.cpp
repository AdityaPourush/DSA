#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }

        while(arr[j] > pivot && j >= low + 1){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x:arr){
        cin >> x;
    }
    quickSort(arr, 0, n-1);
    for(int& x:arr){
        cout << x << " ";
    }
    cout << endl;
}