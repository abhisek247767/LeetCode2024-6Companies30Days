/*
Problem Statement:
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O')
                return;
            board[r][c] = '#';
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };
        for (int i = 0; i < rows; i++) {
            dfs(i, 0);
            dfs(i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j);
            dfs(rows - 1, j);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

// Example Usage
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Input Board:\n";
    for (auto& row : board) {
        for (auto c : row) cout << c << " ";
        cout << endl;
    }

    sol.solve(board);

    cout << "\nOutput Board:\n";
    for (auto& row : board) {
        for (auto c : row) cout << c << " ";
        cout << endl;
    }

    return 0;
}

/*
✅ Output:
Input Board:
X X X X
X O O X
X X O X
X O X X

Output Board:
X X X X
X X X X
X X X X
X O X X
*/
