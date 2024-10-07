#include <iostream>
#include <vector>

using namespace std;

void printTill(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    printTill(n-1);
}

int sumTillN(int n){
    if(n == 1){
        return 1;
    }
    return n + sumTillN(n-1);
}

int nFibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return nFibonacci(n-1) + nFibonacci(n-2);
}

bool isSorted(vector<int> arr, int n){
    int s = arr.size();
    if(n == s-1){
        return true;
    }
    if(arr[n] > arr[n+1]){
        return false;
    }
    return isSorted(arr, n+1);
}

int firstOccurance(vector<int>& arr, int k, int n){
    int s = arr.size();
    if(n == s){
        return -1;
    }
    if(arr[n] == k){
        return n;
    }
    return firstOccurance(arr, k, n+1);
}

int lastOccurance(vector<int>& arr, int k, int n){
    if(n < 0){
        return -1;
    }
    if(arr[n] == k){
        return n;
    }
    return lastOccurance(arr, k, n-1);
}

int optimisedPower(int a, int n){
    if(n == 0){
        return 1;
    }
    int pow = optimisedPower(a, n/2);
    if(n %2 == 0){
        return pow * pow;
    }
    return a * pow * pow;
}

int tilingWays(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return tilingWays(n-1) + tilingWays(n-2);
}

int freindsPairing(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return freindsPairing(n-1) + ((n-1) * freindsPairing(n-2));
}

// print all binary strings of size n without consecutive ones.
void binaryStrings(int n, string str, int lastFilled){
    if(n == 0){
        cout << str << endl;
        return;
    }
    binaryStrings(n-1, str+"0", 0);
    if(lastFilled == 0){
        binaryStrings(n-1, str+"1", 1);
    }
}

int main(){
    int n;
    cin >> n;
    // printTill(n);
    // int sum = sumTillN(n);
    // cout << sum;
    // cout << nFibonacci(n);
    // vector<int> arr(n);
    // for(int i=0; i<n; i++){
    //     cin >> arr[i];
    // }
    // // cout << isSorted(arr,0);
    // cout << lastOccurance(arr, 5, n);
    
    // cout << optimisedPower(n, 10);

    // cout << tilingWays(n);

    // cout << freindsPairing(n);

    binaryStrings(n, "", 0);

    return 0;
}