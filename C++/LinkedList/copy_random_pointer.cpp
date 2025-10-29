// 138. Copy List with Random Pointer
// Problem Statement: A linked list is given where each node has a next pointer and a random pointer. 
// Return a deep copy of the list.
//
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: A deep copy of the list
// Explanation: Each node is copied with both next and random pointers preserved.
//
// Constraints:
// - The number of nodes in the list is in the range [0, 1000].
// - -10^4 <= Node.val <= 10^4
//
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val): val(_val), next(NULL), random(NULL) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};
