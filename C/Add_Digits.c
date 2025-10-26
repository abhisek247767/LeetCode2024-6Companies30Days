#include <stdio.h>

/* Function to repeatedly add digits until one digit remains */
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
    printf("Result: %d\n", result);

    return 0;
}
