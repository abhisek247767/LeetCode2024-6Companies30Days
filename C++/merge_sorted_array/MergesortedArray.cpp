/*
# Problem Statement:
You are given two sorted integer arrays, nums1 and nums2. 
Merge nums2 into nums1 as one sorted array.

# Approach:
1. Append elements of nums2 to nums1 starting at index m.
2. Sort the merged array to get the final sorted result.

# Time Complexity: O((m + n) * log(m + n))
# Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy elements from nums2 to nums1 starting from position m
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        // Sort the combined array
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution s;

    int m, n;
    cout << "Enter size of nums1: ";
    cin >> m;
    cout << "Enter size of nums2: ";
    cin >> n;

    vector<int> nums1(m + n, 0);
    vector<int> nums2(n);

    cout << "Enter elements of nums1 (first " << m << " sorted elements): ";
    for (int i = 0; i < m; i++) cin >> nums1[i];

    cout << "Enter elements of nums2 (sorted): ";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    s.merge(nums1, m, nums2, n);

    cout << "Merged sorted array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    return 0;
}
