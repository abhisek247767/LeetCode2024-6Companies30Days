// 61. Rotate List
// Problem Statement: Given the head of a linked list, rotate the list to the right by k places.
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Explanation: After rotating right twice, the list becomes [4,5,1,2,3].
//
// Constraints:
// - The number of nodes is in the range [0, 500].
// - -100 <= Node.val <= 100
// - 0 <= k <= 2 * 10^9
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* curr = head;
        int len = 1;
        while (curr->next) {
            curr = curr->next;
            len++;
        }
        curr->next = head; 
        k = k % len;
        int steps = len - k;
        while (steps--) curr = curr->next;
        ListNode* newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};
