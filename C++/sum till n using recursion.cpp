#include <iostream>
#include <vector>

using namespace std;

int sumRecursion(int num){
    if(num == 0){
        return 0;
    }
    return num + sumRecursion(num-1);
}

int main(){
    int n;
    cin >> n;
    int ans = sumRecursion(n);
    cout << ans;
    return 0;
}