#include <iostream>
#include <vector>

using namespace std;

bool wordSearch(vector<vector<char>> board, string word, int i, int j, int n, int m, string curr){
    // base cases
    if(curr == word){
        return true;
    }
    if(i >= n || i<0 || j >= m || j < 0 || board[i][j] == -1){
        return false;
    }

    curr += board[i][j];

    if(curr.length() > word.length() || curr[curr.length()-1] != word[curr.length()-1]){
        return false;
    }

    char temp = board[i][j];
    // visited
    board[i][j] = -1;

    if(wordSearch(board, word, i+1, j, n, m, curr)){
        return true;
    }
    if(wordSearch(board, word, i, j+1, n, m, curr)){
        return true;
    }
    if(wordSearch(board, word, i-1, j, n, m, curr)){
        return true;
    }
    if(wordSearch(board, word, i, j-1, n, m, curr)){
        return true;
    }
    board[i][j] = temp;
    return false;
}

int main(){
    vector<vector<string>> board = {{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
    string word = "ABCCED";
    int n = board.size();
    

    return 0;
}