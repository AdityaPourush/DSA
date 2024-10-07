#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void allPermutations(vector<int>& arr, vector<int>& res) {
    if (arr.empty()) {
        printArr(res);
        return;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        int current = arr[i];
        res.push_back(current);
        arr.erase(arr.begin() + i);
        
        allPermutations(arr, res);
        
        // Backtrack
        arr.insert(arr.begin() + i, current);
        res.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    vector<int> res;
    allPermutations(arr, res);

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void allPermutations(vector<int>& arr, int start) {
    if (start == arr.size() - 1) {
        printArr(arr);
        return;
    }
    
    int n = arr.size();
    for(int i=start; i<n; i++){
        swap(arr[i], arr[start]);
        allPermutations(arr, start + 1);
        swap(arr[i], arr[start]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    // vector<int> res;
    allPermutations(arr, 0);

    return 0;
}