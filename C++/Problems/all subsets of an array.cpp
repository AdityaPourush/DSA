#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void allSubSets(vector<int>& arr, vector<int>& res, int i){
    int n = arr.size();
    if(n == i){
        printArr(res);
        return;
    }
    res.push_back(arr[i]);
    allSubSets(arr, res, i+1);

    res.pop_back();
    allSubSets(arr, res, i+1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> res;
    allSubSets(arr, res, 0);

    return 0;
}