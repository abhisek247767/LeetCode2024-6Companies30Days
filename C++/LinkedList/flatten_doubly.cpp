// Flatten a Multilevel Doubly Linked List
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
