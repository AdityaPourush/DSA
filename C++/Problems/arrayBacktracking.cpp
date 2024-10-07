#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int i, int n){
    if(i == n){
        printArr(arr, n);
        return;
    }
    arr[i] = i+1;
    changeArr(arr, i+1, n);
    arr[i] = arr[i] - 2;
}

int main(){
    int arr[5] = {0};
    int n = 5;
    changeArr(arr, 0, n);
    printArr(arr, n);

    return 0;
}