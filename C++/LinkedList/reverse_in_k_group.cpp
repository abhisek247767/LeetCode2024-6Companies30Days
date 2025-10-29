// 25. Reverse Nodes in k-Group
// Problem Statement: Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer <= length of the list. 
// If nodes left < k, leave them as-is.
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Explanation: Nodes are reversed in groups of 2.
//
// Constraints:
// - The number of nodes is in the range [1, 5000].
// - 0 <= Node.val <= 1000
// - 1 <= k <= length of the list
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy, *curr, *nxt;
        int count = 0;
        for (curr = head; curr; curr = curr->next) count++;
        while (count >= k) {
            curr = prev->next;
            nxt = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy.next;
    }
};
