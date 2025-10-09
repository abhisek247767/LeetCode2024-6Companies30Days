// Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Time Complexity: O(N), where N is the number of bars in the elevation map. We iterate through the array once.
// Space Complexity: O(1). We only use a few pointers, so the space is constant.

/**
 * @param {number[]} height
 * @return {number}
 */
const trap = function(height) {
    // If the map has 2 or fewer bars, it's impossible to trap water.
    if (height.length <= 2) {
        return 0;
    }

    let totalWater = 0;
    
    // We use a two-pointer approach to solve this efficiently.
    // 'left' pointer starts from the beginning, 'right' from the end.
    let left = 0;
    let right = height.length - 1;

    // 'maxLeft' keeps track of the maximum height seen from the left.
    // 'maxRight' keeps track of the maximum height seen from the right.
    let maxLeft = 0;
    let maxRight = 0;

    // The loop continues as long as the two pointers don't cross.
    while (left < right) {
        // We work with the shorter of the two sides because the amount of water
        // trapped at any point is limited by the shorter of the two maximum walls.

        if (height[left] <= height[right]) {
            // The left wall is shorter or equal.
            // Check if the current left wall is greater than the maxLeft we've seen.
            if (height[left] > maxLeft) {
                // If it is, update maxLeft. No water can be trapped at this new max height.
                maxLeft = height[left];
            } else {
                // If the current wall is shorter than maxLeft, it means water can be trapped.
                // The amount of water is the difference between maxLeft and the current height.
                totalWater += maxLeft - height[left];
            }
            // Move the left pointer inwards.
            left++;
        } else {
            // The right wall is shorter.
            // Check if the current right wall is greater than the maxRight we've seen.
            if (height[right] > maxRight) {
                // If it is, update maxRight.
                maxRight = height[right];
            } else {
                // If the current wall is shorter than maxRight, trap water.
                totalWater += maxRight - height[right];
            }
            // Move the right pointer inwards.
            right--;
        }
    }
    
    return totalWater;
};

// --- Example ---
const elevationMap = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
const trappedWater = trap(elevationMap);
console.log(`Elevation Map: [${elevationMap.join(', ')}]`);
console.log(`Amount of trapped water: ${trappedWater}`);
// output: 6
