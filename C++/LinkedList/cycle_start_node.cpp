// 142. Linked List Cycle II
// Problem Statement: Given the head of a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.
//
// Input: head = [3,2,0,-4], pos = 1
// Output: Node with value = 2
// Explanation: The tail connects to node index 1, so cycle starts at node with value 2.
//
// Constraints:
// - The number of nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
// - pos is -1 or a valid index in the linked list.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
