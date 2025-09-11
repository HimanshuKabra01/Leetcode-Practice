// Last updated: 9/11/2025, 10:21:15 PM
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        //horizontal
        for(int j = 0; j < col; j++) {
            if(board[row][j] == 'Q') {
                return false;
            } 
        }

        //vertical
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        //diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        for(int i = row, j = col; i >= 0 && j < n; i--,j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void nQueen(vector<string>& board, int& count, int n, int row) {
        if(row == n) {
            count++;
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q'; 
                nQueen(board, count, n, row+1);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;

        nQueen(board, count, n, 0);

        return count;
    }
};