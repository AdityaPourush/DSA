// Given an array of size N. Find the highest and lowest frequency element.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr.push_back(c);
    }

    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]] += 1;
    }

    // for(auto x: mpp){
    //     cout << x.first << " " << x.second << endl;
    // }
    
    int minfreq = n, maxfreq = 0;
    int minEl = 0, maxEl = 0;
    
    for(auto x: mpp){
        int number = x.first;
        int freq = x.second;
        
        if(freq > maxfreq){
            maxfreq = freq;
            maxEl = number;
        }
        
        if(freq < minfreq){
            minfreq = freq;
            minEl = number;
        }
    }
    
    cout << "max freq element: " << maxEl << endl;
    cout << "min freq element: " << minEl;

    return 0;
}