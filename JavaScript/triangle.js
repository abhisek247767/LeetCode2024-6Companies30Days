// 120. Triangle
// Problem Statement : Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you 
// may move to either index i or index i + 1 on the next row. 

//Time Complexity: O(n^2) where n is the number of rows in the triangle.
// Space Complexity: O(n^2) for the DP table used to store intermediate results.

function minimumTotal(triangle) {
    const n = triangle.length;
    const f = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));

    for (let i = n - 1; i >= 0; --i) {
        for (let j = 0; j <= i; ++j) {
            f[i][j] = Math.min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
        }
    }

    return f[0][0];
}


// Input:

// triangle = [
//   [2],
//   [3, 4],
//   [6, 5, 7],
//   [4, 1, 8, 3]
// ]


// Output:
// 11

// Explanation:
// The minimum path sum from top to bottom is:
// 2 → 3 → 5 → 1 = 11