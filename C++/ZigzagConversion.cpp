// C++ program to convert a string in zigzag pattern

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to convert a string into a zigzag pattern
string convert(string s, int numRows) {
    // Edge case: if number of rows is 1, the result is the same as the input string
    if (numRows == 1) return s;

    // Create a vector of strings to store characters of each row
    vector<string> rows(min(numRows, int(s.size())));

    int currentRow = 0;
    bool goingDown = false;

    // Traverse the input string
    for (char c : s) {
        rows[currentRow] += c;  // Append the current character to the current row

        // If we are in the top or bottom row, we change direction
        if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;

        // Move to the next row depending on the direction
        currentRow += goingDown ? 1 : -1;
    }

    // Concatenate all rows to get the final zigzag pattern string
    string result;
    for (string row : rows) {
        result += row;
    }

    return result;
}

/* Driver program to test the function */
int main() {
    // Test case 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Zigzag conversion of \"" << s1 << "\" with " << numRows1 << " rows: " << convert(s1, numRows1) << endl;

    // Test case 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Zigzag conversion of \"" << s2 << "\" with " << numRows2 << " rows: " << convert(s2, numRows2) << endl;

    // Test case 3
    string s3 = "A";
    int numRows3 = 1;
    cout << "Zigzag conversion of \"" << s3 << "\" with " << numRows3 << " rows: " << convert(s3, numRows3) << endl;

    return 0;
}
