/*
Problem Statement:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Time Complexity: O(m * n * 4^L)   // L = length of the word
Space Complexity: O(L)             // recursion stack space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int,int,int)> dfs = [&](int i, int j, int k) {
            if (k == word.size()) return true;
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k]) return false;
            
            char temp = board[i][j];
            board[i][j] = '#';
            bool found = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) || 
                         dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
            board[i][j] = temp;
            return found;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(i, j, 0))
                    return true;
        return false;
    }
};

// Example Usage
int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    Solution sol;
    bool result = sol.exist(board, word);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

/*
✅ Output:
true
*/
