/*
# Problem: Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Example 2:
Input: height = [1,1]
Output: 1
 
## Approach
1. Initialize two pointers (i = 0 and j = n - 1) and a variable maxArea = 0 to store the maximum water.
2. Calculate the area formed by the two lines at indices i and j.
3. Update maxArea if the current area is larger.
4. Move the pointer with the smaller height inward to potentially find a larger area.
5. Repeat the process until the two pointers meet.
*/
/*Solution Implementation: */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
int maxAreaWater(vector<int> &height)
{
    int n = height.size();
    int maxwater = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
       // Move the pointer that points to the shorter line inward
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
       // Calculate the width between the two lines
        int w = j - i;
        int h = min(height[i], height[j]);
      // Calculate the area of the current container
        int area = w * h; 
        maxwater = max(maxwater, area);
    }
    return maxwater;// Return the maximum water area found
}
};
/*

## Time and Space Complexity:
- Time Complexity: O(n) — We only traverse the array once using two pointers.

- Space Complexity: O(1) — No extra space is used except for a few variables

## Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

*/