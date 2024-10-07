#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void secondSL(vector<int> &arr){
    int s = arr.size();
    int min = INT_MAX;
    int secondMin = INT_MAX;
    int max = INT_MIN;
    int secondMax = INT_MIN;
    for(int i=0; i<s; i++){
        if(arr[i] < min){
            secondMin = min;
            min = arr[i];
        }
        if(arr[i] < secondMin && arr[i] > min){
            secondMin = arr[i];
        }
        if(arr[i] > max){
            secondMax = max;
            max = arr[i];
        }
        if(arr[i] > secondMax && arr[i] < max){
            secondMax = arr[i];
        }
    }
    cout << secondMax << endl;
    cout << secondMin;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x:arr){
        cin >> x;
    }
    secondSL(arr);

    return 0;
}