// Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Time Complexity: O(N), where N is the number of bars in the elevation map. We iterate through the array once.
// Space Complexity: O(1). We only use a few pointers, so the space is constant.

/**
 * @param {number[]} height
 * @return {number}
 */
const trap = function(height) {

    if (height.length <= 2) {
        return 0;
    }

    let totalWater = 0;
    

    let left = 0;
    let right = height.length - 1;


    let maxLeft = 0;
    let maxRight = 0;


    while (left < right) {

        if (height[left] <= height[right]) {

            if (height[left] > maxLeft) {
                maxLeft = height[left];
            } else {
                totalWater += maxLeft - height[left];
            }
            left++;
        } else {
            if (height[right] > maxRight) {
                maxRight = height[right];
            } else {
                totalWater += maxRight - height[right];
            }
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
