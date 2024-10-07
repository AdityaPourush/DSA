#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> makeUnion(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    set<int> combi;
    for(int i=0; i<n; i++){
        combi.insert(arr1[i]);
    }
    for(int j=0; j<m; j++){
        combi.insert(arr2[j]);
    }

    vector<int> Union;
    for(auto &item : combi){
        Union.push_back(item);
    }
    return Union;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr1(n);
    for(int &x:arr1){
        cin >> x;
    }
    int m;
    cin >> m;
    vector <int> arr2(m);
    for(int &x:arr2){
        cin >> x;
    }
    vector < int > Union = makeUnion(arr1, arr2);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union){
        cout << val << " ";
    }

    return 0;
}