/*
Add Digits Algorithm (Digital Root)

Description:
Given an integer `num`, repeatedly add all its digits until the result has only one digit.
This problem can be solved efficiently using the concept of the digital root.

Approach:
- If num == 0, the result is 0.
- Otherwise, the digital root can be found using the formula:
      result = (num % 9 == 0) ? 9 : (num % 9)
  This works because in base 10, digital roots repeat every 9.

Use Cases:
- Checking numerology values
- Simplifying large numbers in mathematical puzzles
- Verifying checksum patterns

Time Complexity: O(1)
Reason: The result is calculated using a direct mathematical formula.

Space Complexity: O(1)
Reason: Uses only a few integer variables, no extra space required.
*/

#include <stdio.h>

// Returns the digital root of a given integer
int addDigits(int num) {
    if (num == 0)
        return 0;
    else if (num % 9 == 0)
        return 9;
    else
        return num % 9;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = addDigits(num);

    printf("The single-digit result is: %d\n", result);

    /*
    Example:
    Input:  38
    Output: 2
    Explanation:
        38 → 3 + 8 = 11
        11 → 1 + 1 = 2
    */
    return 0;
}
