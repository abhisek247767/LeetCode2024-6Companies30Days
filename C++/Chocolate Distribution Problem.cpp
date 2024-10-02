# Chocolate Distribution Problem :-

[Problem Link] :--- (https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)

<h3>
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that: <br><br>
1. Each student gets exactly one packet.<br>
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.<br><br>

Example 1:<br>
Input:<br>
N = 8, M = 5<br>
A = {3, 4, 1, 9, 56, 7, 9, 12}<br>
Output: 6<br>
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.<br><br>

Example 2:<br>
Input:<br>
N = 7, M = 3<br>
A = {7, 3, 2, 4, 9, 12, 56}<br>
Output: 2<br>
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following M packets :{3, 2, 4}.<br><br>

Your Task:<br>
You don't need to take any input or print anything. Your task is to complete the function findMinDiff() which takes array A[ ], N and M as input parameters and returns the minimum possible difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student. <br>

Expected Time Complexity: O(N*Log(N))<br>
Expected Auxiliary Space: O(1)<br<br><br>


Constraints:<br>
1 ≤ T ≤ 100<br>
1 ≤ N ≤ 105<br>
1 ≤ Ai ≤ 109<br>
1 ≤ M ≤ N<br>
  
</h3>

***Solution***

```

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());
    int i=0;
    int r=m-1;
    int mini=INT_MAX;
    int ans=0;
    while(r<n){
        ans=a[r]-a[i];
        mini=min(mini,ans);
        i++;
        r++;
    }
    return mini;
    
    }   
};

```
