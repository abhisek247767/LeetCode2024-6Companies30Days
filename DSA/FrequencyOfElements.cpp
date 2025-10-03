/*
Problem: Frequency of Elements

Given an array of integers, find the frequency of each element.

Input:
- First line: integer n (size of array)
- Second line: n integers (array elements)

Output:
- Print each unique element with its frequency.

Constraints:
1 <= n <= 10^5
-10^9 <= arr[i] <= 10^9

Example:
Input:
5
1 2 2 3 1

Output:
1 -> 2
2 -> 2
3 -> 1

Approach:
We use a map (or unordered_map) to count the occurrences of each element in O(n) time.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    map<int,int> freq;  // use map for sorted output, unordered_map for faster but unordered
    for (int x : nums) freq[x]++;

    for (auto &p : freq) cout << p.first << " -> " << p.second << "\n";
    return 0;
}
