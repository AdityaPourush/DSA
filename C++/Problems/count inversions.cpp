#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int left, int mid, int right){
    vector<int> temp;
    int l = left;
    int r = mid+1;
    int count = 0;

    while(l <= mid && r <= right){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else {
            temp.push_back(arr[r]);
            count += (mid - left + 1);
            r++;
        }
    }
    while(l <= mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r <= right){
        temp.push_back(arr[r]);
        r++;
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
    return count;
}

int countInversions(vector<int> &arr, int left, int right){
    int count = 0;
    if(left >= right){
        return count;
    }
    int mid = (left + right )/2;
    count += countInversions(arr, left, mid);
    count += countInversions(arr, mid+1, right);
    count += merge(arr, left, mid, right);
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int inversions = countInversions(arr, 0, n-1);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}