
/*
Problem Statement:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool Check_Duplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> un_map;
        for (int i = 0; i < n; i++) {
            un_map[arr[i]]++;
        }
        for (auto k : arr) {
            if (un_map[k] >= 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 19, 4, 19, 11 };  

    bool result = solution.Check_Duplicate(nums);
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
