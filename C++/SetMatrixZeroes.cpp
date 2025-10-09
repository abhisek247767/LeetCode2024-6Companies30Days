/*
Problem Statement:
Given an m x n integer matrix, if an element is 0, 
set its entire row and column to 0. Do it in-place.

Time Complexity: O(m * n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Mark zeroes in first row/col
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstCol = true;
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRow = true;

        // Mark rest of matrix
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        // Apply marks
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // Handle first row/col
        if (firstRow)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (firstCol)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};

// Example Usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Input Matrix:\n";
    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    sol.setZeroes(matrix);

    cout << "\nOutput Matrix:\n";
    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
✅ Output:
Input Matrix:
1 1 1
1 0 1
1 1 1

Output Matrix:
1 0 1
0 0 0
1 0 1
*/
