// 37. Sudoku Solver (Hard) (https://leetcode.com/problems/sudoku-solver/)
// problem statement: Write a program to solve a Sudoku puzzle by filling the empty cells.

// Time Complexity=O(9^m), where m is the number of empty cells.
// Space Complexity=O(m)
class Solution {
    private boolean ok;
    private char[][] board;
    private List<Integer> t = new ArrayList<>();
    private boolean[][] row = new boolean[9][9];
    private boolean[][] col = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.add(i * 9 + j);
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        dfs(0);
    }

    private void dfs(int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t.get(k) / 9, j = t.get(k) % 9;
        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                board[i][j] = (char) (v + '1');
                dfs(k + 1);
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
            }
            if (ok) {
                return;
            }
        }
    }
}

// Output

// The method modifies the input board in place.
// After calling solveSudoku(board), the same board will hold the solved Sudoku grid.

// Example Input:

// char[][] board = {
//   {'5','3','.','.','7','.','.','.','.'},
//   {'6','.','.','1','9','5','.','.','.'},
//   {'.','9','8','.','.','.','.','6','.'},
//   {'8','.','.','.','6','.','.','.','3'},
//   {'4','.','.','8','.','3','.','.','1'},
//   {'7','.','.','.','2','.','.','.','6'},
//   {'.','6','.','.','.','.','2','8','.'},
//   {'.','.','.','4','1','9','.','.','5'},
//   {'.','.','.','.','8','.','.','7','9'}
// };


// Output (after solveSudoku(board)):

// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9