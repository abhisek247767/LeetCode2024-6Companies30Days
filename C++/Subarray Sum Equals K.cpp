# Subarray Sum Equals K :-

[Problem Link] :--- (https://leetcode.com/problems/subarray-sum-equals-k/description/)

<h3>
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.<br><br>
A subarray is a contiguous non-empty sequence of elements within an array.<br><br>

Example 1:<br>
Input: nums = [1,1,1], k = 2<br>
Output: 2<br><br>

Example 2:<br>
Input: nums = [1,2,3], k = 3<br>
Output: 2<br><br>
 
Constraints:<br>
1 <= nums.length <= 2 * 104<br>
-1000 <= nums[i] <= 1000<br>
-107 <= k <= 107<br><br>
  
</h3>

***Solution***

```

class Solution {
public:
    int subarraySum(vector<int>& arr , int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0 ; i < n ; i++)
        {
            int sum = arr[i];
            if (sum == k)
            {
                ans ++;
            }
            for (int j = i + 1 ; j < n ; j++ )
            {
                sum += arr[j];
                if( sum == k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

```
