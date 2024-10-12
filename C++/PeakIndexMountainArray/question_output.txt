# Problem: Peak Index in a Mountain Array

You are given an integer mountain array `arr` of length `n` where the values increase to a peak element and then decrease.

Your task is to find and return the index of the peak element in O(log(n)) time complexity.

## Example 1:

**Input**: arr = [0,1,0]
**Output**: 1

## Example 2:

**Input**: arr = [0,2,1,0]
**Output**: 1

## Example 3:

**Input**:arr = [0,10,5,2]
**Output**: 1

## Constraints:

- `3 <= arr.length <= 10^5`
- `0 <= arr[i] <= 10^6`
- The array is guaranteed to be a mountain array.