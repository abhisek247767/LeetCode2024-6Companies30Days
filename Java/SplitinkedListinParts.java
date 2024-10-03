// Split Linked List in Parts

// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null. The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later. Return an array of the k parts.

// Example 1:
// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]

// Example 2:
// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]

package Mediumtasks;
public class SplitLinkedList {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    class Solution {
        public ListNode[] splitListToParts(ListNode head, int k) {
            int length = 0;
            ListNode current = head;
            while (current != null) {
                length++;
                current = current.next;
            }

            int partSize = length / k;
            int largerParts = length % k;

            ListNode[] result = new ListNode[k];
            current = head;

            for (int i = 0; i < k; i++) {
                ListNode partHead = current;
                int currentPartSize = partSize + (i < largerParts ? 1 : 0);

                for (int j = 0; j < currentPartSize - 1 && current != null; j++) {
                    current = current.next;
                }

                if (current != null) {
                    ListNode nextPart = current.next;
                    current.next = null;
                    current = nextPart;
                }

                result[i] = partHead;
            }

            return result;
        }
    }
    public static void main(String[] args) {
        SplitLinkedList splitList = new SplitLinkedList();
        Solution solution = splitList.new Solution();


        ListNode head = splitList.new ListNode(1);
        head.next = splitList.new ListNode(2);
        head.next.next = splitList.new ListNode(3);
        head.next.next.next = splitList.new ListNode(4);
        head.next.next.next.next = splitList.new ListNode(5);

        int k = 3;


        ListNode[] result = solution.splitListToParts(head, k);


        for (int i = 0; i < result.length; i++) {
            System.out.print("Chapter " + (i + 1) + ": ");
            ListNode current = result[i];
            while (current != null) {
                System.out.print(current.val + " ");
                current = current.next;
            }
            System.out.println();
        }
    }
}


