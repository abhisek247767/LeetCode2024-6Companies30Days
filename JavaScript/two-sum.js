function twoSum(nums, target) {
    const seen = new Map(); // Use Map for better performance on large datasets

    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const complement = target - num;

        if (seen.has(complement)) {
            return [seen.get(complement), i]; // Return the pair of indices
        }

        seen.set(num, i); // Store the current number with its index
    }

    throw new Error("No two sum solution found");
}

// Example usage
const nums = [2, 7, 11, 15];
const target = 9;

console.log(twoSum(nums, target)); // Output: [0, 1]
