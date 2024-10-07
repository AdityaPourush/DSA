#include <iostream>
#include <vector>
using namespace std;

int gridWays(int cr, int cc, int dr, int dc, string turns){
    // base case
    if(cr == dr && cc == dc){
        cout << turns << endl;
        return 1;
    }
    // stopping down & right overflow
    if(cr > dr || cc > dc){
        return 0;
    }
    
    // adding smaller cases when either the pointer moves one right or one down
    return gridWays(cr+1, cc, dr, dc, turns+"D") + gridWays(cr, cc+1, dr, dc, turns+"R");
}

int main(){
    int cr = 1;
    int cc = 1;
    int dr = 3;
    int dc = 3;
    int ways = gridWays(cr, cc, dr, dc, "");
    cout << "ways : " << ways;
    
    return 0;
}