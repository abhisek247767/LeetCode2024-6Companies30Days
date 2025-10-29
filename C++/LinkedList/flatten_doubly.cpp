// 430. Flatten a Multilevel Doubly Linked List
// Problem Statement: You are given a doubly linked list, which in addition to the next and previous pointers, 
// it could have a child pointer. Flatten the list so that all nodes appear in a single-level doubly linked list.
//
// Input: 1--2--3
//           |
//           4--5
// Output: 1--2--3--4--5
// Explanation: Child list is inserted into the main list.
//
// Constraints:
// - The number of nodes in the list is in the range [0, 1000].
//
// Time Complexity: O(n)
// Space Complexity: O(n) in worst case (stack)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val): val(_val), prev(NULL), next(NULL), child(NULL) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* curr = head;
        stack<Node*> st;
        while (curr) {
            if (curr->child) {
                if (curr->next) st.push(curr->next);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            if (!curr->next && !st.empty()) {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};
