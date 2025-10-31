/*
* C++ Solution for LeetCode 217: "Contains Duplicate"
*
* Problem: Determine if any value appears at least twice in an array.
* Solution uses an unordered_set (hash set) for O(n) time complexity.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> seenNumbers;

        for (int num : nums) {
            // Check if the number is already in the set
            if (seenNumbers.count(num)) {
                // Found a duplicate
                return true;
            }
            // If not found, add it to the set
            seenNumbers.insert(num);
        }

        // No duplicates were found after checking all numbers
        return false;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = sol.containsDuplicate(nums1);
    std::cout << "Test Case 1 (Expected true): " << (result1 ? "true" : "false") << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = sol.containsDuplicate(nums2);
    std::cout << "Test Case 2 (Expected false): " << (result2 ? "true" : "false") << std::endl;

    std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    bool result3 = sol.containsDuplicate(nums3);
    std::cout << "Test Case 3 (Expected true): " << (result3 ? "true" : "false") << std::endl;

    return 0;
}