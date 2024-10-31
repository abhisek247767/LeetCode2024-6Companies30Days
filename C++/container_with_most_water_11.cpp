#include<bits/stdc++.h>
using namespace std;

//Leetcode 11. Container With Most Water
// Problem link: https://leetcode.com/problems/container-with-most-water/
// Approach: Two pointer approach
// Time complexity: O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l=0, r = height.size()-1;
        while(l<r){
            max_area = max(max_area,  (r-l)*min(height[l],height[r]));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return max_area;
    }
};