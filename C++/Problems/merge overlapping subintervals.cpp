#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        // checking if interval already merged
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        // another loop to check for next intervals
        for(int j=i+1; j<n; j++){
            if(intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }
        vector<int> temp = {start, end};
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin >> intervals[i][j];
        }
    }

    vector<vector<int>> merged = merge(intervals);
    for(int i=0; i<merged.size(); i++){
        for(int j=0; j<2; j++){
            cout << merged[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}