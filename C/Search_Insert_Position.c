#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    
    // Target not found, left is the insertion index
    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int index = searchInsert(nums, numsSize, target);
    printf("Index: %d\n", index);

    target = 2;
    index = searchInsert(nums, numsSize, target);
    printf("Index: %d\n", index);

    return 0;
}
