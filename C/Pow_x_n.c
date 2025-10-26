#include <stdio.h>

/* Function to compute x^n using fast exponentiation */
double myPow(double x, int n) {
    long long N = n; // Handle negative n safely
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}

int main() {
    double x;
    int n;
    
    printf("Enter base x: ");
    scanf("%lf", &x);
    
    printf("Enter exponent n: ");
    scanf("%d", &n);

    double result = myPow(x, n);
    printf("Result: %.5lf\n", result);

    return 0;
}
