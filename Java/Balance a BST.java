/*
# Problem: Balance a Binary Search Tree (BST)
You are given the root of a Binary Search Tree (BST).  
The task is to return a balanced BST with the same nodes as the original tree.  
A balanced tree is defined as a tree where the depth of the two subtrees of every node never differs by more than 1.

## Approach:
1. **Inorder Traversal**: First, traverse the given BST in an **inorder** manner to collect the node values in a sorted list.
2. **Balanced Tree Construction**: Use the sorted list to build a **balanced BST** recursively.
   - Choose the middle element of the list to be the root of the subtree.
   - Recursively build the left subtree using the left half of the list and the right subtree using the right half.
3. Return the root of the newly created balanced BST.

## Example:
Input: A skewed tree with nodes [1, 2, 3, 4, 5]  
Output: A balanced BST with the same nodes

## Constraints:
- The number of nodes in the tree is in the range [1, 10^4].
- The node values are unique.

## Solution Implementation:
*/

import java.util.ArrayList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    // Constructors for different ways of creating TreeNodes
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    // Main function to balance the BST
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer> sortedList = new ArrayList<>();
        // Collect the nodes using inorder property
        inorderTraversal(root, sortedList);
        // Build the BST
        return buildBalancedTree(sortedList, 0, sortedList.size() - 1);
    }

    // Helper function to perform inorder traversal and collect node values
    private void inorderTraversal(TreeNode node, ArrayList<Integer> list) {
        if (node == null) return;
        inorderTraversal(node.left, list);  // Traverse the left subtree
        list.add(node.val);         // Add the current node value
        inorderTraversal(node.right, list); // Traverse the right subtree
    }

    // Helper function to build a balanced BST 
    private TreeNode buildBalancedTree(ArrayList<Integer> list, int start, int end) {
        if (start > end) return null;  // Base case

        int mid = start + (end - start) / 2; // Find mid
        TreeNode root = new TreeNode(list.get(mid)); // Create new root

        // Recursively build left and right tree
        root.left = buildBalancedTree(list, start, mid - 1);
        root.right = buildBalancedTree(list, mid + 1, end);

        return root;  // Return the newly created subtree root
    }
}

/*
## Time and Space Complexity:
- **Time Complexity**: O(n) — Inorder traversal and tree reconstruction each take O(n) time.
- **Space Complexity**: O(n) — We store all node values in a list of size n.

This approach ensures that the tree is balanced while preserving all original nodes.
*/
