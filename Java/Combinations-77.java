// 77. Combinations (https://leetcode.com/problems/combinations/)
// Problem statement: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//Time complexity: O(C(n, k) * k) where C(n, k) is the binomial coefficient
//Space complexity: O(k × C(n, k)) (including output), O(n) auxiliary

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int n;
    private int k;

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        dfs(1);
        return ans;
    }

    private void dfs(int i) {
        if (t.size() == k) {
            ans.add(new ArrayList<>(t));
            return;
        }
        if (i > n) {
            return;
        }
        t.add(i);
        dfs(i + 1);
        t.remove(t.size() - 1);
        dfs(i + 1);
    }
}


// Input: n = 4, k = 2

// Combinations Generated:

// [1,2]
// [1,3]
// [1,4]
// [2,3]
// [2,4]
// [3,4]


// Output:

// [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
