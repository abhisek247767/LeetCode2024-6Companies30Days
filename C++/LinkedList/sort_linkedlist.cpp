// 148. Sort List
// Problem Statement: Given the head of a linked list, return the list after sorting it in ascending order.
//
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Explanation: Applying merge sort results in a sorted list.
//
// Constraints:
// - The number of nodes is in the range [0, 5 * 10^4].
// - -10^5 <= Node.val <= 10^5
//
// Time Complexity: O(n log n), merge sort
// Space Complexity: O(log n), recursion stack

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *p = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) { p->next = l1; l1 = l1->next; }
            else { p->next = l2; l2 = l2->next; }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};
