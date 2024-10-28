#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Question Details
// Given a string `s`, partition `s` such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of `s`.

// Constraints
// - 1 <= s.length <= 16
// - `s` consists only of lowercase English letters.

// Input
// - A single string `s` to partition into palindromic substrings.

// Output
// - A 2D vector of strings where each sub-vector contains a valid palindromic partition of `s`.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        helper(0, s, path, ans);
        return ans;
    }

private:
    void helper(int index, string s, vector<string>& path, vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1)); 
                helper(i + 1, s, path, ans); 
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) { 
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    cout << "Enter a string to partition into palindromic substrings: ";
    cin >> s;

    Solution solution;
    vector<vector<string>> result = solution.partition(s);

    cout << "All possible palindromic partitions:\n";
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
