// Problem:
// You are given a doubly linked list (DLL) where the nodes are sorted in non-decreasing order.
//  Some values in the DLL may be repeated consecutively. Write a program to remove all duplicate nodes
//   from the DLL such that each value appears only once.

// Input:

// A vector of integers representing the elements of the DLL in order.
// Example: {1, 1, 1, 3, 3, 4, 5, 5}

// Output:

// The elements of the DLL before removing duplicates.
// The elements of the DLL after removing duplicates.

// Functions in the code:

// creatingDLL(vector<int>& vec): Creates a doubly linked list from a vector.
// removeDuplicate(Node* head): Removes consecutive duplicate elements from a sorted doubly linked list.

// ✅ Total time complexity: O(n)

// Space Complexity

// The algorithm uses no extra data structures, only pointers to traverse the DLL.
// DLL nodes themselves are stored dynamically.

// ✅ Auxiliary space complexity: O(1)
// ✅ Overall space including nodes: O(n)

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    public:
    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};

Node* creatingDLL(vector<int>& vec){
    Node* head=new Node(vec[0]);
    Node* temp=head;
    for(int i=1;i<vec.size();i++){
        Node* temp1=new Node(vec[i]);
        temp->next=temp1;
        temp1->prev=temp;
        temp=temp1;
    }
    return head;
}

Node* removeDuplicate(Node* head){
    Node* curr=head->next;
    while(curr){
        Node* back=curr->prev;
        Node* front=curr->next;

        if(curr->val==back->val){
            back->next=front;
            if(front)front->prev=back;
            free(curr);
        }
        curr=curr=front;
    }
    return head;
}

int main(){
    vector<int>v={1,1,1,3,3,4,5,5};
    Node* head=creatingDLL(v);
    Node* temp=head;
    for(Node* i=temp;i!=NULL;i=i->next){
        cout<<i->val<<"\n";
    }
    cout<<"After removing duplicates \n";
    Node* head1=removeDuplicate(head);
    Node* temp1=head1;
    for(Node* i=temp1;i!=NULL;i=i->next){
        cout<<i->val<<"\n";
    }
    return 0;
}