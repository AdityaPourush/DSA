#include <iostream>
#include <vector>

using namespace std;

int lengthOf(string str, int n, int count){
    if(!str[n]){
        return count;
    }
    return lengthOf(str, n+1, count+1);
}

int main(){
    string str;
    cin >> str;
    cout << "Length : " << lengthOf(str, 0, 0);

    return 0;
}