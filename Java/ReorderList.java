package problems.Linkedlist;

// Leetcode 143: Reorder List

/*
 * Problem Statement:
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 *
 * My Logic:
 * 1. Find the middle of the linked list using the slow and fast pointer
 * technique.
 * 2. Reverse the second half of the linked list.
 * 3. Merge the two halves, alternating nodes from each half.
 * 4. Ensure the end of the merged list points to null.
 *
 * Dry Run:
 *
 * Example: head = [1,2,3,4]
 * 1. Find Middle:
 * - Initialize slow and fast pointers at head (1).
 * - Move slow by 1 step and fast by 2 steps until fast reaches the end.
 * - Slow ends at node (3), which is the middle.
 *
 * 2. Reverse Second Half:
 * - Second half starts from node (4).
 * - Reverse the list starting from (4) to get (4).
 * 3 -> 4 -> null becomes 4 -> 3 -> null.
 *
 * 3. Merge Two Halves:
 * - First half: 1 -> 2 -> null
 * - Second half (reversed): 4 -> 3 -> null
 * - Merge:
 *  - 1 -> 4 -> 2 -> 3 -> null
 * Final reordered list: [1,4,2,3]
 */

public class ReorderList {
  int val;
  ReorderList next;
  ReorderList() {}
  ReorderList(int val) { this.val = val; }
  ReorderList(int val, ReorderList next) {
    this.val = val;
    this.next = next;
  }
}

class Solution {
  public void reorderList(ReorderList head) {
    ReorderList middle = FindMiddle(head);
    ReorderList secondHalf = reverseLL(middle.next);
    middle.next = null;
    mergeList(head, secondHalf);
  }

  public ReorderList FindMiddle(ReorderList head) {
    ReorderList slow = head;
    ReorderList fast = head;

    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }
    return slow;
  }

  public ReorderList reverseLL(ReorderList head) {
    ReorderList curr = head;
    ReorderList prev = null;
    ReorderList next = null;

    while (curr != null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  public void mergeList(ReorderList first, ReorderList second) {
    while (second != null) {
      ReorderList temp1 = first.next;
      ReorderList temp2 = second.next;

      first.next = second;
      second.next = temp1;

      first = temp1;
      second = temp2;
    }
  }
}