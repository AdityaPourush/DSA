// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    // Transpose of matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // Reversing each row of matrix
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}