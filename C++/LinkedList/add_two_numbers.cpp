// 2. Add Two Numbers
// Problem Statement: You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each node contains a single digit. 
// Add the two numbers and return the sum as a linked list.
//
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
//
// Constraints:
// - The number of nodes in each list is in the range [1, 100].
// - 0 <= Node.val <= 9
//
// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};
