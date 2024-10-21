/*Problem:
Link of the problem:https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
You are given an array words of size n consisting of non-empty strings.
We define the score of a string term as the number of strings words[i] such that term is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Print(Return) an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.*/
/*
Example 1:
Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.

Example 2:
Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
 
Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists of lowercase English letters.
*/

///+++++++++++++++++++++++++++++++Solution++++++++++++++++++++++++++++++++/////////////////
/*
Approach: Trie Data Structure
To solve this efficiently, we can use a Trie (Prefix Tree). A Trie allows us to store and count how many times each prefix of a word has been inserted.

Key Insights:
Trie Structure:
A Trie is a tree-like data structure where each node represents a character of a word.
Each node has an array of children, one for each possible character ('a' to 'z' in this case).
We store how many words pass through a node (prefix count).

Insertion into Trie:
As we insert each word, we traverse the Trie and increment the value at each node, indicating how many words share that prefix.
After inserting a word, we mark the last node as the end of the word.

Summing Prefix Scores:
For each word, traverse its path in the Trie and sum the values stored in the nodes corresponding to its characters. This sum represents how many words share each prefix of the word.

Steps to Solve:

*.Insert all words into the Trie:
*As we insert, we increase the prefix count at each node.
*For each word, compute the sum of prefix counts:
*For each word, traverse the Trie and sum up the values of the nodes corresponding to the word's prefixes.
*Return the result for all words:
*After computing the prefix sum for each word, store it in a result vector and return it.
*/

////////+++++++++++++++++++Time Complexity+++++++++++++++++++++++++++++//
/* 
Time Complexity:
Insertion into the Trie:
Inserting a word of length L into the Trie takes O(L). For n words of average length L, this takes O(n × L).

Computing Prefix Sums:
For each word, computing the prefix sum also takes O(L) for n words, leading to O(n × L).
Thus, the overall time complexity is O(n × L), where n is the number of words and L is the average word length.

Space Complexity:
The space complexity is O(n × L) due to the space required to store the Trie, where n is the number of words and L is the average length of the words.
*/

//////////Code 
#include <bits/stdc++.h>
using namespace std;

// Trie node definition
struct Trie {
    Trie* child[26];
    int value;
    bool endWord;

    // Constructor to initialize the Trie node
    Trie() {
        endWord = false;
        value = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    // Destructor to free up the dynamically allocated memory
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (child[i] != nullptr) {
                delete child[i];
            }
        }
    }

    // Function to insert a word into the Trie
    void insert(Trie* root, string s) {
        Trie* curr = root;
        for (char c : s) {
            // If the child node for the current character doesn't exist, create it
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new Trie();
            }
            curr = curr->child[c - 'a'];
            curr->value++;  // Increment the count of words passing through this node
        }
        curr->endWord = true;  // Mark the end of a word
    }

    // Function to compute the sum of prefix values for a given word
    int summ(Trie* root, string s) {
        int t = 0;
        Trie* curr = root;
        for (char c : s) {
            // Traverse the Trie for each character in the word
            curr = curr->child[c - 'a'];
            if (curr == nullptr)
                break;
            t += curr->value;  // Add the value of the current node
        }
        return t;
    }
};

// Solution class
class Solution {
public:
    // Function to compute the prefix scores for a list of words
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();  // Create the Trie root

        // Insert all words into the Trie
        for (string s : words) {
            root->insert(root, s);
        }

        vector<int> ans;

        // For each word, calculate the sum of prefix scores
        for (string s : words) {
            ans.push_back(root->summ(root, s));
        }

        delete root;  // Delete the Trie to free memory
        return ans;
    }
};
/////////-----------------Create object of class ------------///
int main() {
    // Read input as per the example
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution sol;
    vector<int> result = sol.sumPrefixScores(words);

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
