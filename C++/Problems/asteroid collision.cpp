#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> collide(vector<int> &asteroids){
    vector<int> temp;
    temp.push_back(asteroids[0]);
    int s= asteroids.size();
    for(int i=1; i<s; i++){
        int ts = temp.size();
        if (temp[temp.size()-1]>0 && asteroids[i]<0)
        {
            if(abs(temp[temp.size()-1]) == abs(asteroids[i])){
                temp.pop_back();
            } else if(abs(temp[temp.size()-1]) > abs(asteroids[i])){
                continue;
            } else {
                while(abs(temp[ts-1]) < abs(asteroids[i])){
                    temp.pop_back();
                    ts-=1;
                }
                if(abs(temp[temp.size()-1]) == abs(asteroids[i])){
                    temp.pop_back();
                } else {
                    temp.push_back(asteroids[i]);
                }
            }
        } else{
            temp.push_back(asteroids[i]);
        }
    }
    return temp;
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> res = collide(arr);
    int k = res.size();
    if(k == 0){
        cout << "Everything Destroyed";
    }
    for(int i=0; i<k; i++){
        cout << res[i] << " ";
    }
}