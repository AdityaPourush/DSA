#include <iostream>
#include <vector>

using namespace std;

void printSudoku(vector<vector<int>>& sudoku){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& sudoku, int row, int col, int digit){
    // vertical check
    for(int i=0; i<9; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // horizontal check
    for(int j=0; j<9; j++){
        if(sudoku[row][j] == digit){
            return false;
        }
    }

    // int the box check
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i=startRow; i<startRow+3; i++){
        for(int j=startCol; j<startCol+3; j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>>& sudoku, int row, int col){
    // base case
    if(row >= 9){
        printSudoku(sudoku);
        return;
    }

    int nextRow = row;
    int nextCol = col+1;
    if(nextCol >= 9){
        nextRow = row+1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for(int i = 1; i<=9; i++){
        if(isSafe(sudoku, row, col, i)){
            sudoku[row][col] = i;
            if(sudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> sudoku(9, vector<int>(9));  // Initialising the inner vector as well.
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }

    printSudoku(sudoku);
    return 0;
}