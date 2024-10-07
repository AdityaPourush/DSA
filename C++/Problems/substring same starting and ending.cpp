#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSameStartAndEnd(string str, int start, int end, int n){
    if(n == 1){
        return 1;
    }
    if(n <= 0){
        return 0;
    }
    int res = countSameStartAndEnd(str, start+1, end, n-1) 
    + countSameStartAndEnd(str, start, end-1, n-1) 
    - countSameStartAndEnd(str, start+1, end-1, n-2);

    if(str[start] == str[end]){
        res += 1;
    }

    return res;
}

int main(){
    string str;
    cin >> str;
    cout << countSameStartAndEnd(str, 0, str.length()-1, str.length());

    return 0;
}