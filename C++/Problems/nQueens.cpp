#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(vector<vector<char>>& board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<char>>& board, int row, int col){
    int n = board.size();
    // checking horizontal safety
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    
    // checking vertical safety
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    
    // checking left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    
    // checking diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>>& board, int row){
    int n = board.size();
    // base case
    if(row == n){
        printBoard(board);
        return 1;
    }
    
    int count = 0;
    // finding all cases to fill board
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            // if queen is eligible to be placed there i.e. isSafe returns true
            board[row][j] = 'Q';
            count += nQueens(board, row + 1);
            board[row][j] = '.'; // backtracking -> removing Q, so as to let fill the next column
        }
    }
    return count;  // no of possible solutions at each level
}

int main(){
    // to make a board
    vector<vector<char>> board;
    int n = 5;
    
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int patternCount = nQueens(board, 0);
    cout << "Count : " << patternCount;
}