class Solution {
public:
    bool isSafe(int row, int col, char ch, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // Check row and column
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;

            // Check 3x3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isSafe(row, col, ch, board)) {
                            board[row][col] = ch;
                            if (solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false; // No valid number fits here
                }
            }
        }
        return true; // Solved successfully
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
