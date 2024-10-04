// C++ program to swap every two adjacent nodes in a linked list

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to swap every two adjacent nodes
ListNode* swapPairs(ListNode* head) {
    // If the list is empty or has only one node, no swaps needed
    if (!head || !head->next) return head;

    // Initialize pointers
    ListNode* newHead = head->next;  // The second node will be the new head
    ListNode* prev = NULL;
    ListNode* curr = head;

    // Traverse the list in pairs
    while (curr && curr->next) {
        ListNode* nextPair = curr->next->next; // Store the start of the next pair
        ListNode* second = curr->next;         // The second node in the current pair

        // Swap the current pair
        second->next = curr;
        curr->next = nextPair;
        
        // If this is not the first pair, link the previous pair to the current one
        if (prev) {
            prev->next = second;
        }

        // Move the pointers forward
        prev = curr;
        curr = nextPair;
    }

    return newHead; // Return the new head of the swapped list
}

/* Function to print the linked list */
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

/* Driver program to test the function */
int main() {
    // Example 1: head = [1, 2, 3, 4]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Original List 1: ";
    printList(head1);
    ListNode* result1 = swapPairs(head1);
    cout << "Swapped List 1: ";
    printList(result1);

    // Example 2: head = []
    ListNode* head2 = NULL;
    cout << "Original List 2: ";
    printList(head2);
    ListNode* result2 = swapPairs(head2);
    cout << "Swapped List 2: ";
    printList(result2);

    // Example 3: head = [1]
    ListNode* head3 = new ListNode(1);
    cout << "Original List 3: ";
    printList(head3);
    ListNode* result3 = swapPairs(head3);
    cout << "Swapped List 3: ";
    printList(result3);

    // Example 4: head = [1, 2, 3]
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    cout << "Original List 4: ";
    printList(head4);
    ListNode* result4 = swapPairs(head4);
    cout << "Swapped List 4: ";
    printList(result4);

    return 0;
}
