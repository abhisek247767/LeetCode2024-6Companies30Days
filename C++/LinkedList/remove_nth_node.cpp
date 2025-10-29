// 19. Remove Nth Node From End of List
// Problem Statement: Given the head of a linked list, remove the nth node from the end and return its head.
//
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Explanation: The second node from the end is 4. Removing it leaves [1,2,3,5].
//
// Constraints:
// - The number of nodes in the list is sz (1 <= sz <= 30).
// - 0 <= Node.val <= 100
// - 1 <= n <= sz
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy, *second = &dummy;
        for (int i = 0; i <= n; i++) first = first->next;
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
};
