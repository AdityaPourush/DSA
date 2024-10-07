#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maxRectangleArea(vector<int> &arr){
    int n = arr.size();
    int maxArea = 0;

    for(int i=0; i<n; i++){
        int minHeight = arr[i];
        for(int j=i; j<n; j++){
            minHeight = min(minHeight, arr[j]);
            int width = j-i+1;
            int area = width * minHeight;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main(){
    int n;
    cout << "The number of rectangles are: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int area = maxRectangleArea(arr);
    cout << area;

    return 0;
}