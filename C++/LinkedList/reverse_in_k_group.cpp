// Reverse Nodes in k-Group
#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL){} };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy, *curr, *nxt;
        int count = 0;
        for (curr = head; curr; curr = curr->next) count++;
        while (count >= k) {
            curr = prev->next;
            nxt = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy.next;
    }
};
