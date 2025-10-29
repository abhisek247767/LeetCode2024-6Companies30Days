// 141. Linked List Cycle
// Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.
// A cycle exists if some node can be reached again by continuously following the next pointer.
//
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle where the tail connects to the 1st node (value = 2).
//
// Constraints:
// - The number of nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
// - pos is -1 or a valid index in the linked list.
//
// Time Complexity: O(n), traverse each node at most twice.
// Space Complexity: O(1), only pointers used

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
