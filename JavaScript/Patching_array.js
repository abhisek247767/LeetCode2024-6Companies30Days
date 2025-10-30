// 330. Patching Array

//Problem Statement:Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
//Return the minimum number of patches required.

// Time Complexity: O(m), where m = nums.length
// Space Complexity: O(1)

function minPatches(nums, n) {
    let x = 1;
    let ans = 0;
    for (let i = 0; x <= n; ) {
        if (i < nums.length && nums[i] <= x) {
            x += nums[i++];
        } else {
            ++ans;
            x *= 2;
        }
    }
    return ans;
}


// Input:

// nums = [1, 3];
// n = 6;


// Output:
// 1

// Explanation:

// Initially x = 1, which means we can form numbers [1, 1) → none yet.
// nums[0] = 1 ≤ x, so x = 1 + 1 = 2 (we can now form [1]).
// Next nums[1] = 3 > x, so we patch with x = 2, increment ans = 1, and double x = 4.
// Now nums[1] = 3 ≤ x, so x = 4 + 3 = 7.
// Since x > n (7 > 6), we stop.
// Only 1 patch (2) was added.