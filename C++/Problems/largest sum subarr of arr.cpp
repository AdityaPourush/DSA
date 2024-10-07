// Given an integer array arr. write a program to find the
// subarray which has the largest sum and return its sum.
// If the array is empty (say n-O), print O.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int largestSum(vector<int> &arr)
{
    int s = arr.size();
    
    int sum = arr[0];
    int temp_sum = arr[0];

    for (int i = 1; i < s; i++)
    {
        temp_sum += arr[i];
        if(temp_sum < arr[i]){
            temp_sum = arr[i];
        }
        if (temp_sum > sum)
        {
            sum = temp_sum;
        }
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = largestSum(arr);
    cout << res;
}