// reverse an array

#include <iostream>
#include<algorithm>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start += 1;
        end -= 1;
        reverseArray(arr, start, end);
    }
}

int main()
{
    int art[] = { 1, 2, 3 };
    // reverseArray(art, 0, 2);
    int size = sizeof(art) / sizeof(art[0]);
    
    reverse(art, art+size);           // pre-defined in algorithm library
    for(int i = 0; i< size; i++){
        cout << art[i] << " ";
    }


    return 0;
}