/* 
Problem Statement: For a given m x n grid, where each cell has the following values : 

2  -  represents a rotten orange
1  -  represents a Fresh orange
0  -  represents an Empty Cell

Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 
Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

Example: 
Input: grid - [ [2,1,1] , [0,1,1] , [1,0,1] ]
Output: -1

Time Complexity: O ( n x n ) x 4    
Space Complexity: O ( n x n )

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        queue<pair<int, int>> rotpos; // Queue to store positions of rotten oranges
        int total = 0; // Total count of oranges (rotten + fresh)
        int cnt = 0;   // Count of oranges rotten by the end

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) rotpos.push({i, j}); // If rotten, push to rotpos queue
                if (grid[i][j] != 0) total++;             // Count all non-empty cells as oranges
            }
        }

        // 4 possible movement directions (up, down, left, right)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int minutes = 0; // Counter for minutes 

        while (!rotpos.empty()) {
            int k = rotpos.size(); // Number of oranges to process for this day
            cnt += k; // Increase the rotten count by k

            // Process all oranges at the current min. level
            while (k--) {
                int x = rotpos.front().first, y = rotpos.front().second;
                rotpos.pop();

                // Check for fresh oranges to rot
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];

                    // Skip if out of bounds or if not a fresh orange
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;

                    // Rot the fresh orange and add it to queue
                    grid[nx][ny] = 2;
                    rotpos.push({nx, ny});
                }
            }

            // Increment minutes if there are more oranges to process in the queue
            if (!rotpos.empty()) minutes++;
        }

        return total == cnt ? minutes : -1;
    }
};
