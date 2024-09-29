// C++ program to add two numbers represented by linked list

#include <iostream>  // for standard input/output
using namespace std;

// Linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented by linked list
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // Dummy node to simplify the process
    ListNode* p = l1, * q = l2, * current = dummyHead;
    int carry = 0;
    
    // Traverse both lists
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;  // Take value of l1 node, or 0 if l1 is done
        int y = (q != NULL) ? q->val : 0;  // Take value of l2 node, or 0 if l2 is done
        int sum = carry + x + y;           // Sum current digits and carry
        carry = sum / 10;                  // Update carry
        current->next = new ListNode(sum % 10); // Create new node for the current digit
        current = current->next;
        
        if (p != NULL) p = p->next;        // Move to the next node in l1
        if (q != NULL) q = q->next;        // Move to the next node in l2
    }
    
    // If there is a carry left after the last digits, add a new node for it
    if (carry > 0) {
        current->next = new ListNode(carry);
    }
    
    return dummyHead->next; // The actual sum starts from dummyHead->next
}

/* Driver program to test the function */
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Function call
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Sum: ";
    printList(result);

    return 0;
}
