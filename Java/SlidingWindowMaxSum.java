/*
Problem Statement:
Given an array of integers and a number k, find the maximum sum of a contiguous subarray of size k using the Sliding Window Algorithm.

Time Complexity: O(n), where n is the number of elements in the array.
Space Complexity: O(1), constant extra space used.

Output:
Prints the maximum sum of any subarray of size k.
*/

public class SlidingWindowMaxSum {

    // Function to find maximum sum of a subarray of size k
    public static int maxSum(int[] arr, int k) {
        int n = arr.length;

        if (n < k) {
            System.out.println("Invalid: Array size is less than k.");
            return -1;
        }

        // Compute sum of first window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        // Slide the window: subtract element going out and add element coming in
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }

    // Driver code
    public static void main(String[] args) {
        int[] arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
        int k = 4;

        int result = maxSum(arr, k);
        System.out.println("Maximum sum of a subarray of size " + k + " is: " + result);
    }
}
