#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void removeDuplicates(string str, int n, string stri, vector<bool>& vect){
    int s = str.size();
    if(n == s){
        cout << stri; 
    }
    if(vect[str[n]-'a'] == true){
        removeDuplicates(str, n+1, stri, vect);
    }
    else {
        vect[str[n]-'a'] = true;
        removeDuplicates(str, n+1, stri+str[n], vect);
    }
}

int main(){
    string str;
    cin >> str;
    vector<bool> vect(26, false);
    removeDuplicates(str, 0, "", vect);

    return 0;
}