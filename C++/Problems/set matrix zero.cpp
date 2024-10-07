#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& matrix, int row){
    int n = matrix[0].size();
    for(int i=0; i<n; i++){
        if(matrix[row][i] != 0){
            matrix[row][i] = -1;
        }
    }
}

void markColumn(vector<vector<int>>& matrix, int col){
    int m = matrix.size();
    for(int i=0; i<m; i++){
        if(matrix[i][col]!=0){
            matrix[i][col] = -1; 
        }
    }
}

void setZeros(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, i);
                markColumn(matrix, j);
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}


int main(){
    int n, m;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            cin >> arr[i][j];
        }
    }
    setZeros(arr);
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}