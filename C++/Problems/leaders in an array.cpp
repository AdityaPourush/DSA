#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arrayLeaders(vector<int>& arr){
    int s = arr.size();
    vector<int> ans;
    for(int i=0; i<s; i++){
        bool leader = true;
        for(int j=i; j<s; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> arrayLeaders(vector<int>& arr){
    int s = arr.size();
    int leftMax = arr[s-1];
    vector<int> ans;
    for(int i=s-1; i>=0; i--){
        if(arr[i] >= leftMax){
            ans.push_back(arr[i]);
            leftMax = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int s;
    cin >> s;
    vector<int> arr(s);
    for(int i=0; i<s; i++){
        cin >> arr[i];
    }
    vector<int> ans = arrayLeaders(arr);
    int ansSize = ans.size();
    for(int i=0; i<ansSize; i++){
        cout << ans[i] << " ";
    }
    return 0;
}