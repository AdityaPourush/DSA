#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    
                    long long sum = nums[i] + nums[j];
                    sum = sum+nums[k];
                    sum = sum+nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum2(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> store;  // stores the elements from j to k to search for l
            for(int k=j+1; k<n; k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long remains = target-sum;
                if(store.find(remains) != store.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(remains)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                store.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum3(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j = i+1; j<n; j++){
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }

            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> ans = fourSum3(nums, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}