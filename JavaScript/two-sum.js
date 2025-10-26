function twoSum(nums, target) {
    const numMap = {}; // To store numbers and their indices

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];

        // Check if the complement exists in the map
        if (numMap[complement] !== undefined) {
            return [numMap[complement], i];
        }

        // Store the current number with its index
        numMap[nums[i]] = i;
    }

    throw new Error("No two sum solution found");
}

// Example Usage
const nums = [2, 7, 11, 15];
const target = 9;
console.log(twoSum(nums, target)); // Output: [0, 1]
