// 78. Subsets

// Problem Statement: Given an integer array nums of unique elements, return all possible subsets (the power set).

// Time Complexity: O(2ⁿ × n)
// (each subset requires O(n) to copy elements)
// Space Complexity: O(n)
// (recursion depth + temporary array t)

function subsets(nums) {
    const ans = [];
    const t = [];
    const dfs = (i) => {
        if (i === nums.length) {
            ans.push(t.slice());
            return;
        }
        dfs(i + 1);
        t.push(nums[i]);
        dfs(i + 1);
        t.pop();
    };
    dfs(0);
    return ans;
}



// Input:

// nums = [1, 2, 3];


// Output:

// [
//   [], 
//   [3], 
//   [2], 
//   [2, 3], 
//   [1], 
//   [1, 3], 
//   [1, 2], 
//   [1, 2, 3]
// ]


// Explanation:
// The function uses DFS (backtracking) to explore all combinations of elements.
// For n elements, there are 2^n possible subsets.
