/*
Power Function Implementation

Description:
Implements the pow(x, n) function to calculate x raised to the power n.
Uses the standard library function `pow()` from <math.h> for simplicity.

Approach:
- Directly use the `pow()` function which computes x^n.
- For educational or algorithmic purposes, this can also be implemented
  manually using fast exponentiation (binary exponentiation).

Use Cases:
- Mathematical computations
- Physics and engineering formulas
- Financial or statistical modeling

Time Complexity: O(1)
Reason: Uses the optimized internal implementation of `pow()`.

Space Complexity: O(1)
Reason: Only a few variables are used, no additional data structures.
*/

#include <stdio.h>
#include <math.h>

// Computes x raised to the power n
double myPow(double x, int n) {
    return pow(x, n);
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    scanf("%lf", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    double result = myPow(x, n);
    printf("Result: %.5lf\n", result);

    /*
    Example Test Cases:
    Input:  x = 2.00000, n = 10
    Output: 1024.00000

    Input:  x = 2.10000, n = 3
    Output: 9.26100

    Input:  x = 2.00000, n = -2
    Output: 0.25000
    */

    return 0;
}
