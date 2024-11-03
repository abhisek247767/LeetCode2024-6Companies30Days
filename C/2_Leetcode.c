/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Add two numbers represented by linked lists.
 * Return the sum as a linked list.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;

        current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
        current->next = NULL;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);  // Free the dummy head
    return result;
}
