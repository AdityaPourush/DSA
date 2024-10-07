#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> makeUnion(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i=0, j = 0;
    vector<int> Union;
    
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(Union.size() == 0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        } else{
            if(Union.size() == 0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (Union.back() != arr1[i]){
            Union.push_back(arr1[i]);
        }
    i++;
    }

    while (j < m)
    {
        if (Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
        }
    j++;
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