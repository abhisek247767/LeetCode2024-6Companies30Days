# Problem Statement: LeetCode 283 - Move Zeroes
# Move all zeros to the end of the array while maintaining the order of non-zero elements.
# Time Complexity: O(N)
# Space Complexity: O(1)

def moveZeroes(nums):
    pos = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[pos], nums[i] = nums[i], nums[pos]
            pos += 1
    return nums

# Example
print(moveZeroes([0,1,0,3,12]))  # Output: [1,3,12,0,0]
