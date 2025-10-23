/*
Problem Statement:
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. 
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Approach:
- Perform DFS from all border 'O's and mark them as safe.
- Flip remaining 'O's to 'X'.
- Restore safe cells back to 'O'.

Time Complexity: O(N * M)   (Each cell is visited at most once)
Space Complexity: O(N * M)  (Recursion stack in worst case)

Example:
Input:
X X X X
X O O X
X X O X
X O X X

Output:
X X X X
X X X X
X X X X
X O X X
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') 
            return;

        board[i][j] = '#';  // mark as safe
        for (auto &dir : directions) {
            dfs(board, i + dir[0], j + dir[1]);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();

        // Step 1: Mark border-connected 'O' as safe
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }

        // Step 2: Flip remaining 'O' -> 'X' and restore safe '#' -> 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    sol.solve(board);

    cout << "Final Board:\n";
    for (auto &row : board) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Expected Output:
Final Board:
X X X X
X X X X
X X X X
X O X X
*/
