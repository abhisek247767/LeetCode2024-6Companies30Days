function twoSum(nums, target) {
    const numMap = {};

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];

        if (numMap[complement] !== undefined) {
            return [numMap[complement], i];
        }

        numMap[nums[i]] = i; // Store the index of the current number
    }

    throw new Error("No two sum solution found");
}

// Example Usage
const nums = [2, 7, 11, 15];
const target = 9;
console.log(twoSum(nums, target)); // Output: [0, 1]


// feature/two-sum