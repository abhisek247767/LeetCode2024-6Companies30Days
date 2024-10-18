// C++ program to check if a tree is BST

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to find max value in the subtree
int maxValue(Node* node) {
    if (node == nullptr) 
        return INT_MIN;
    return max({node->data, 
                maxValue(node->left), 
                maxValue(node->right)});
}

// Function to find min value in the subtree
int minValue(Node* node) {
    if (node == nullptr) 
        return INT_MAX;
    return min({node->data, 
                minValue(node->left), 
                minValue(node->right)});
}

// Returns true if the binary tree is a BST
bool isBST(Node* node) {
    if (node == nullptr)
        return true;

    // Check if the max of the left subtree 
    // is greater than current node
    if (node->left != nullptr && maxValue(node->left) >= node->data)
        return false;

    // Check if the min of the right subtree 
    // is smaller than or equal to current node
    if (node->right != nullptr && minValue(node->right) <= node->data)
        return false;

    // Recursively check if left and right subtrees are BSTs
    return isBST(node->left) && isBST(node->right);
}

int main() {
  
    // Create a sample binary tree
    //      4
    //    /   \
    //   2     5
    //  / \
    // 1   3

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

     if (isBST(root)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
    