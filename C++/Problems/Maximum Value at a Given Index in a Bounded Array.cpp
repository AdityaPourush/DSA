#include <iostream>
#include <vector>

using namespace std;

int maxValue(int n, int index, int maxSum){
    int low = 1;
    int high = maxSum;

    int emptyR = n-index-1;
    int emptyL = index;

    long long res = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        int leftSum = 0;
        int rightSum = 0;
        int el = mid-1;

        if(emptyR <= el){
            rightSum = ((el*(el+1))/2) - (((el-emptyR) * (el-emptyR+1))/2); 
        }
        else {
            rightSum = ((el*(el+1))/2) + (el-emptyR);
        }

        if(emptyL <= el){
            leftSum = ((el*(el+1))/2) - (((el-emptyL) * (el-emptyL+1))/2);
        }
        else {
            leftSum = ((el*(el+1))/2) + (el-emptyL);
        }

        long long sum = leftSum + mid + rightSum;

        if(sum <= maxSum){
            low = mid + 1;
            res = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int index;
    cin >> index;
    int maxSum;
    cin >> maxSum;

    int value = maxValue(n, index, maxSum);
    cout << value;

    return 0;
}