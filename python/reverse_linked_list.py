"""
Problem Statement:
Reverse a singly linked list.
Given the head of a singly linked list, reverse the list and return the new head.

Time Complexity: O(n)
Space Complexity: O(1)
Input:1->2->3->4->5->NULL

Output: 5->4->3->2->1->NULL
"""
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        z=head
        t=None
        t2=None
        while(z!=None):
            t2=z.next
            z.next=t
            t=z
            z=t2
        z=t    
        return z
