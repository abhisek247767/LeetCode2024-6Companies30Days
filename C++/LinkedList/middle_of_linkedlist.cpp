// 876. Middle of the Linked List
// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. 
// If there are two middle nodes, return the second middle node.
//
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node is 3.
//
// Constraints:
// - The number of nodes in the list is in the range [1, 100].
// - 1 <= Node.val <= 100
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
