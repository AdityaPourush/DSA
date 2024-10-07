#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leftRotate(vector<int> &arr){
    int last = arr[0];
    int s = arr.size();
    for(int i=0; i<s-1; i++){
        arr[i] = arr[i+1];
    }
    arr[s-1] = last;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x:arr){
        cin >> x;
    }

    leftRotate(arr);

    for(int &y:arr){
        cout << y << " ";
    }

    return 0;
}