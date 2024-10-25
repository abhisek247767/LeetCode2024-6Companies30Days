#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // Not enough bars to trap any water
        
        // Arrays to store the maximum height to the left and right of each bar
        vector<int> leftMax(n), rightMax(n);
        
        // Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        // Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        // Calculate the trapped water
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            // The water trapped on the current bar is determined by the
            // minimum of the maximum heights on both sides, minus the current height
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight > height[i]) {
                water += minHeight - height[i];
            }
        }
        
        return water;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap(height);
    cout << "Total water trapped: " << result << " units" << endl;
    
    return 0;
}
