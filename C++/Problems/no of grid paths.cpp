#include <iostream>
#include <vector>

using namespace std;

int noOfPaths(int m, int n){
    if(m == 1 || n == 1){
        return 1;
    }
    return noOfPaths(m, n-1) + noOfPaths(m-1, n);
}

int main(){
    int m;
    cin >> m;
    int n;
    cin >> n;
    int paths = noOfPaths(m, n);
    cout << paths;
    return 0;
}