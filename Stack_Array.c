/*EXPERIMENT : 06
Name : Shrusti Moon
Roll no : UEC2024145

Expt 6: Develop  a program to model an array as stack 
*/

#include<stdio.h>
#define MAX 10

struct stack {
    int stk[MAX];
    int top;
};

// Display function :
void display(struct stack st) {
    if (st.top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("\nStack elements: ");
        for (int i = st.top; i >= 0; i--) {
            printf("%d ", st.stk[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack st;
    st.top = -1;
    int choice = 0, num;

    while (choice != 3) {
        printf("\nSTACK MENU :\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                if (st.top == MAX - 1) {
                    printf("Stack is Full!\n");
                } else {
                    printf("Enter the element to push: ");
                    scanf("%d", &num);
                    st.top++;
                    st.stk[st.top] = num;
                    printf("\n");
                    display(st);
                }
                break;

            case 2: // Pop
                if (st.top == -1) {
                    printf("Stack is Empty!\n");
                } else {
                    num = st.stk[st.top];
                    st.top--;
                    printf("Popped element : %d\n", num); 
                    display(st); 
                }
                break;

            case 3: // Exit
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try Again.\n");
        }
    }
    return 0;
}

/* OUTPUT 
STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 2


Stack elements: 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 4


Stack elements: 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 3


Stack elements: 3 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 8


Stack elements: 8 3 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 5
Invalid choice! Try Again.

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 4


Stack elements: 4 8 3 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 9


Stack elements: 9 4 8 3 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 1
Enter the element to push: 5


Stack elements: 5 9 4 8 3 4 2

STACK MENU :
1. PUSH
2. POP
3. EXIT
Enter your choice: 2
Popped element : 5

Stack elements: 9 4 8 3 4 2

*/