/*
#Problem:  Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or  false otherwise.

Example 1: 
Input: head = [1,2,2,1]
Output: true

Example 2: 
Input: head = [1,2]
Output: false

### Approach to Check if a Singly Linked List is a Palindrome
1. **Edge Case**: Return `true` if the list is empty or has one node.
2. **Count Nodes**: Traverse the list to count the total number of nodes.
3. **Find Midpoint**: Use two pointers to reach the midpoint and disconnect the first half from the second half.
4. **Reverse Second Half**: Reverse the second half of the list.
5. **Compare Halves**: Use two pointers to compare values of the first half and the reversed second half:
   - Return `false` if any values differ.
   - Return `true` if all values match.
*/
/*Solution Implementation: */
#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
            return 1;
        int count = 0;
        ListNode *temp = head;
        //  count no. of nodes
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        count /= 2;
        ListNode *current = head;
        ListNode *prev = NULL;
        //  Findinf Mid to partition
        while (count--)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        ListNode *nextNode = NULL;
        prev = NULL;
        //  reversing partition
        while (current)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        ListNode *first = head;
        ListNode *second = prev;
        //  Evaluating is Palindrome or NOT
        while (first)
        {
            if (first->val != second->val)
                return 0;
            first = first->next;
            second = second->next;
        }
        return 1;
    }
};
/*
### Time and Space Complexity
- **Time Complexity**: **O(n)**  
  - The algorithm traverses the list multiple times (counting, finding midpoint, reversing, and comparing).

- **Space Complexity**: **O(1)**  
  - Only a fixed number of pointers are used, regardless of the list size.

### Constraints:
- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9

*/