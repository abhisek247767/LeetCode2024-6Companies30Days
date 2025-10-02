/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.*/

#include <stdio.h>
#include <stdlib.h>
// Function to return indices of the two numbers
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for returning result
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Brute force check all pairs
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; // return as soon as found
            }
        }
    }

    return NULL; // should never reach here if one solution exists
}

// Driver code
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int* ans = twoSum(nums, 4, target, &returnSize);

    printf("Input: nums = [2,7,11,15], target = 9\n");
    printf("Output: [%d,%d]\n", ans[0], ans[1]);

    free(ans); // free allocated memory
    return 0;
}
/*Input-nums = [2,7,11,15], target = 9
Output-[0,1]
Explanation-We check all pairs:
2 + 7 = 9 → indices [0,1] are returned.
*/