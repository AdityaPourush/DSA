#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int col1 = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] =0;
                } else {
                    col1 = 0;
                }
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int i=0; i<n; i++){
            matrix[0][i] = 0;
        }
    }
    if(col1 == 0){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    int n, m;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    setZeros(matrix);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}