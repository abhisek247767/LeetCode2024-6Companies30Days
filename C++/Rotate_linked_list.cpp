/*

problem statement
Given the head of a linked list, rotate the list to the right by k places.
leetcode qn link: https://leetcode.com/problems/rotate-list/

##Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

##Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/

/*
Solution Implementation
*/

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Initialize variables to be used in the function
        int count = 0;                  // Variable to count the number of nodes in the list
        ListNode* p = head;             // Pointer `p` to traverse the list
        ListNode* r = head;             // Pointer `r` to eventually become the new head after rotation
        ListNode* a = head;             // Pointer `a` to help in counting nodes
        ListNode* q = nullptr;          // Pointer `q` to keep track of the node before the new head (for breaking the list)

        // Count the total number of nodes in the list
        while (a != nullptr) {
            count++;
            a = a->next;               // Move `a` to the next node until the end of the list
        }

        // Edge case: If the list is empty (head is nullptr), return the list as it is
        if (head == nullptr) {
            return head;
        }

        // Calculate the actual number of rotations needed (modulo with the length of the list)
        k = k % count;

        // Calculate the number of steps to move to get the new head (after rotating `k` times)
        int m = count - k;

        // Traverse to the last node in the list
        while (p->next != nullptr) {
            p = p->next;
        }

        // Connect the last node to the current head, making the list circular
        p->next = head;

        // Move the `r` pointer `m` steps forward, where `r` will eventually point to the new head
        for (int i = 0; i < m; i++) {
            q = r;                    // Keep track of the node before `r` (the new head)
            r = r->next;              // Move `r` to the next node
        }

        // The `r` node is now the new head of the rotated list
        head = r;

        // Break the circular list by setting the next pointer of the node before `r` to nullptr
        q->next = nullptr;

        // Return the new head after rotation
        return head;
    }
};

/*

Time Complexity:

Counting the nodes in the list (while (a != nullptr)):
This loop runs once, traversing all the nodes in the list to count them.
Time complexity: O(n), where n is the number of nodes in the list.

Modifying k and computing the new head position:
The operation k = k % count is a constant time operation.
The computation of m = count - k is also a constant time operation.
Time complexity: O(1).

Traversing to the last node (while (p->next != nullptr)):
This loop also traverses all the nodes to reach the last node.
Time complexity: O(n).

Traversing to the new head (for (int i = 0; i < m; i++)):
This loop runs m times, where m = count - k, effectively covering a portion of the list up to the new head.
In the worst case, this could also take n steps (if the rotation is minimal).
Time complexity: O(n).

Overall Time Complexity:
Since each step involves a traversal of the list, the overall time complexity is:  O(n)

Space Complexity: O(1), because the algorithm uses a fixed amount of extra space (pointers p, r, a, q and a few integer variables).

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

*/