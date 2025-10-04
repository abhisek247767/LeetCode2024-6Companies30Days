#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Finding the intersection point in the cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];         // Move slow pointer by 1 step
            fast = nums[nums[fast]];   // Move fast pointer by 2 steps
        } while (slow != fast);        // Loop until they meet inside the cycle

        // Phase 2: Finding the entrance to the cycle (duplicate number)
        slow = nums[0];                // Reset slow to start
        while (slow != fast) {
            slow = nums[slow];         // Move both pointers 1 step at a time
            fast = nums[fast];
        }

        return slow;                   // The duplicate number
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate number is: " << sol.findDuplicate(nums) << endl;
    return 0;
}


//Time Complexity: O(n)
//Space Complexity: O(1)