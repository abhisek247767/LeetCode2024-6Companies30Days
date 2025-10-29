// 160. Intersection of Two Linked Lists
// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which they intersect. 
// If the two linked lists have no intersection, return null.
//
// Input: listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
// Output: Node with value 8
// Explanation: Intersection occurs at node with value 8.
//
// Constraints:
// - The number of nodes in listA is m, in listB is n.
// - 1 <= m, n <= 3 * 10^4
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
