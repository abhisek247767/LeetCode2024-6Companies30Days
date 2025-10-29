// 23. Merge k Sorted Lists
// Problem Statement: You are given an array of k linked-lists, each linked-list is sorted in ascending order. 
// Merge all the linked-lists into one sorted linked-list and return it.
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: Merging the three sorted lists produces a single sorted linked list.
//
// Constraints:
// - k == lists.length
// - 0 <= k <= 10^4
// - 0 <= list[i].length <= 500
// - -10^4 <= Node.val <= 10^4
//
// Time Complexity: O(N log k), where N is the total number of nodes
// Space Complexity: O(k), for priority queue

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto l : lists) if (l) pq.push(l);
        ListNode dummy(0), *tail = &dummy;
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
