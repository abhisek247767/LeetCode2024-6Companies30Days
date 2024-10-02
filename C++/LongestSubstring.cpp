// C++ program to find the length of the longest substring
// without repeating characters

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the length of the longest substring
// without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex; // To store the last index of the characters
    int maxLength = 0; // To store the maximum length of the substring
    int start = 0; // Start index of the current window

    // Traverse the string
    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character is already in the map and is within the current window
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            // Move the start to the right of the last occurrence of the current character
            start = charIndex[currentChar] + 1;
        }

        // Update the last seen index of the current character
        charIndex[currentChar] = end;

        // Calculate the maximum length
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

/* Driver program to test the function */
int main() {
    // Test case 1
    string s1 = "abcabcbb";
    cout << "Length of longest substring without repeating characters in \"" << s1 << "\": " << lengthOfLongestSubstring(s1) << endl;

    // Test case 2
    string s2 = "bbbbb";
    cout << "Length of longest substring without repeating characters in \"" << s2 << "\": " << lengthOfLongestSubstring(s2) << endl;

    // Test case 3
    string s3 = "pwwkew";
    cout << "Length of longest substring without repeating characters in \"" << s3 << "\": " << lengthOfLongestSubstring(s3) << endl;

    return 0;
}
