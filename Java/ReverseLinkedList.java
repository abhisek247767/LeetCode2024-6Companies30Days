/*
 * Problem Statement: Reverse Linked List (LeetCode #206)
 * 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * Example 3:
 * Input: head = []
 * Output: []
 * 
 * Constraints:
 * - The number of nodes in the list is in the range [0, 5000]
 * - -5000 <= Node.val <= 5000
 * 
 * Time Complexity: O(n) - We visit each node exactly once
 * Space Complexity: O(1) - Only using a few pointers (iterative solution)
 *                   O(n) - Recursive call stack (recursive solution)
 * 
 * Approach (Iterative):
 * - Use three pointers: previous, current, and next
 * - Iterate through the list, reversing the direction of each link
 * - Move all three pointers forward until we reach the end
 * - Return the new head (previous pointer at the end)
 */

/**
 * Definition for singly-linked list node
 */
class ListNode {
    int val;
    ListNode next;
    
    // Constructor for single value
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
    
    // Constructor with value and next pointer
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class ReverseLinkedList {
    
    /**
     * Iterative approach to reverse a linked list
     * This is the preferred method with O(1) space complexity
     * 
     * @param head The head of the linked list
     * @return The new head of the reversed list
     */
    public static ListNode reverseListIterative(ListNode head) {
        // Edge case: empty list or single node
        if (head == null || head.next == null) {
            return head;
        }
        
        // Three pointers to track position during reversal
        ListNode previous = null;    // Will become new tail (null)
        ListNode current = head;     // Current node being processed
        ListNode next = null;        // Temporary storage for next node
        
        // Traverse and reverse links
        while (current != null) {
            // Step 1: Save the next node before we lose reference
            next = current.next;
            
            // Step 2: Reverse the link (point current back to previous)
            current.next = previous;
            
            // Step 3: Move previous and current one step forward
            previous = current;
            current = next;
        }
        
        // After loop, previous points to the new head
        return previous;
    }
    
    /**
     * Recursive approach to reverse a linked list
     * More elegant but uses O(n) space due to call stack
     * 
     * @param head The head of the linked list
     * @return The new head of the reversed list
     */
    public static ListNode reverseListRecursive(ListNode head) {
        // Base case: empty list or last node
        if (head == null || head.next == null) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        ListNode newHead = reverseListRecursive(head.next);
        
        // Make the next node point back to current
        head.next.next = head;
        
        // Remove the original forward link
        head.next = null;
        
        // Return the new head (stays same through recursion)
        return newHead;
    }
    
    /**
     * Helper method to create a linked list from an array
     */
    public static ListNode createList(int[] values) {
        if (values == null || values.length == 0) {
            return null;
        }
        
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        
        return head;
    }
    
    /**
     * Helper method to print a linked list
     */
    public static void printList(ListNode head) {
        if (head == null) {
            System.out.println("[]");
            return;
        }
        
        System.out.print("[");
        ListNode current = head;
        
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
        System.out.println("]");
    }
    
    /**
     * Helper method to convert list to array for comparison
     */
    public static int[] listToArray(ListNode head) {
        // Count nodes
        int count = 0;
        ListNode current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        
        // Create array
        int[] result = new int[count];
        current = head;
        for (int i = 0; i < count; i++) {
            result[i] = current.val;
            current = current.next;
        }
        
        return result;
    }
    
    /**
     * Main method with comprehensive test cases
     */
    public static void main(String[] args) {
        System.out.println("=== LeetCode Problem #206: Reverse Linked List ===\n");
        
        // Test Case 1: Normal list with 5 nodes
        System.out.println("Test Case 1: Normal list");
        int[] arr1 = {1, 2, 3, 4, 5};
        ListNode head1 = createList(arr1);
        System.out.print("Original: ");
        printList(head1);
        ListNode reversed1 = reverseListIterative(head1);
        System.out.print("Reversed: ");
        printList(reversed1);
        System.out.println("Expected: [5 -> 4 -> 3 -> 2 -> 1]\n");
        
        // Test Case 2: Two nodes
        System.out.println("Test Case 2: Two nodes");
        int[] arr2 = {1, 2};
        ListNode head2 = createList(arr2);
        System.out.print("Original: ");
        printList(head2);
        ListNode reversed2 = reverseListIterative(head2);
        System.out.print("Reversed: ");
        printList(reversed2);
        System.out.println("Expected: [2 -> 1]\n");
        
        // Test Case 3: Empty list
        System.out.println("Test Case 3: Empty list");
        ListNode head3 = null;
        System.out.print("Original: ");
        printList(head3);
        ListNode reversed3 = reverseListIterative(head3);
        System.out.print("Reversed: ");
        printList(reversed3);
        System.out.println("Expected: []\n");
        
        // Test Case 4: Single node
        System.out.println("Test Case 4: Single node");
        int[] arr4 = {42};
        ListNode head4 = createList(arr4);
        System.out.print("Original: ");
        printList(head4);
        ListNode reversed4 = reverseListIterative(head4);
        System.out.print("Reversed: ");
        printList(reversed4);
        System.out.println("Expected: [42]\n");
        
        // Test Case 5: Longer list with negative numbers
        System.out.println("Test Case 5: List with negative numbers");
        int[] arr5 = {-5, -2, 0, 3, 7, 10};
        ListNode head5 = createList(arr5);
        System.out.print("Original: ");
        printList(head5);
        ListNode reversed5 = reverseListIterative(head5);
        System.out.print("Reversed: ");
        printList(reversed5);
        System.out.println("Expected: [10 -> 7 -> 3 -> 0 -> -2 -> -5]\n");
        
        // Demonstrate recursive approach
        System.out.println("=== Testing Recursive Approach ===\n");
        System.out.println("Test Case 6: Recursive reversal");
        int[] arr6 = {10, 20, 30, 40};
        ListNode head6 = createList(arr6);
        System.out.print("Original: ");
        printList(head6);
        ListNode reversed6 = reverseListRecursive(head6);
        System.out.print("Reversed: ");
        printList(reversed6);
        System.out.println("Expected: [40 -> 30 -> 20 -> 10]\n");
        
        // Algorithm Analysis
        System.out.println("=== Algorithm Analysis ===\n");
        System.out.println("Iterative Approach:");
        System.out.println("  Time Complexity: O(n) - Visit each node once");
        System.out.println("  Space Complexity: O(1) - Only 3 pointers used");
        System.out.println("  Pros: More efficient, no stack overflow risk");
        System.out.println("  Use When: Large lists, memory constraints\n");
        
        System.out.println("Recursive Approach:");
        System.out.println("  Time Complexity: O(n) - Visit each node once");
        System.out.println("  Space Complexity: O(n) - Recursive call stack");
        System.out.println("  Pros: More elegant, easier to understand");
        System.out.println("  Cons: Stack overflow risk with very large lists");
        System.out.println("  Use When: Small/medium lists, code clarity preferred\n");
        
        System.out.println("Key Concepts:");
        System.out.println("1. Three-pointer technique (prev, curr, next)");
        System.out.println("2. In-place reversal (no extra list created)");
        System.out.println("3. Edge cases: null, single node");
        System.out.println("4. Pointer manipulation is key to linked list problems");
        
        System.out.println("\nVisual Example of Reversal Process:");
        System.out.println("Step 0: 1 -> 2 -> 3 -> 4 -> null");
        System.out.println("        ^prev ^curr");
        System.out.println("Step 1: null <- 1   2 -> 3 -> 4 -> null");
        System.out.println("                ^prev ^curr");
        System.out.println("Step 2: null <- 1 <- 2   3 -> 4 -> null");
        System.out.println("                     ^prev ^curr");
        System.out.println("Step 3: null <- 1 <- 2 <- 3   4 -> null");
        System.out.println("                          ^prev ^curr");
        System.out.println("Step 4: null <- 1 <- 2 <- 3 <- 4");
        System.out.println("                               ^prev (new head)");
    }
}

/*
 * Output:
 * === LeetCode Problem #206: Reverse Linked List ===
 * 
 * Test Case 1: Normal list
 * Original: [1 -> 2 -> 3 -> 4 -> 5]
 * Reversed: [5 -> 4 -> 3 -> 2 -> 1]
 * Expected: [5 -> 4 -> 3 -> 2 -> 1]
 * 
 * Test Case 2: Two nodes
 * Original: [1 -> 2]
 * Reversed: [2 -> 1]
 * Expected: [2 -> 1]
 * 
 * Test Case 3: Empty list
 * Original: []
 * Reversed: []
 * Expected: []
 * 
 * Test Case 4: Single node
 * Original: [42]
 * Reversed: [42]
 * Expected: [42]
 * 
 * Test Case 5: List with negative numbers
 * Original: [-5 -> -2 -> 0 -> 3 -> 7 -> 10]
 * Reversed: [10 -> 7 -> 3 -> 0 -> -2 -> -5]
 * Expected: [10 -> 7 -> 3 -> 0 -> -2 -> -5]
 * 
 * === Testing Recursive Approach ===
 * 
 * Test Case 6: Recursive reversal
 * Original: [10 -> 20 -> 30 -> 40]
 * Reversed: [40 -> 30 -> 20 -> 10]
 * Expected: [40 -> 30 -> 20 -> 10]
 * 
 * === Algorithm Analysis ===
 * 
 * Iterative Approach:
 *   Time Complexity: O(n) - Visit each node once
 *   Space Complexity: O(1) - Only 3 pointers used
 *   Pros: More efficient, no stack overflow risk
 *   Use When: Large lists, memory constraints
 * 
 * Recursive Approach:
 *   Time Complexity: O(n) - Visit each node once
 *   Space Complexity: O(n) - Recursive call stack
 *   Pros: More elegant, easier to understand
 *   Cons: Stack overflow risk with very large lists
 *   Use When: Small/medium lists, code clarity preferred
 * 
 * Key Concepts:
 * 1. Three-pointer technique (prev, curr, next)
 * 2. In-place reversal (no extra list created)
 * 3. Edge cases: null, single node
 * 4. Pointer manipulation is key to linked list problems
 * 
 * Visual Example of Reversal Process:
 * Step 0: 1 -> 2 -> 3 -> 4 -> null
 *         ^prev ^curr
 * Step 1: null <- 1   2 -> 3 -> 4 -> null
 *                 ^prev ^curr
 * Step 2: null <- 1 <- 2   3 -> 4 -> null
 *                      ^prev ^curr
 * Step 3: null <- 1 <- 2 <- 3   4 -> null
 *                           ^prev ^curr
 * Step 4: null <- 1 <- 2 <- 3 <- 4
 *                                ^prev (new head)
 */
