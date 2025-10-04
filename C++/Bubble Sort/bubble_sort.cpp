// Problem Statement
// Implement Bubble Sort to sort an array of integers in ascending order.
// Input: An integer n (size of array), followed by n integers.
// Output: The array sorted in ascending order.

// Time Complexity
// Best Case (Already Sorted):
// With optimization (early stop): O(n)
// Without optimization (your current code): O(n²)
// Average Case: O(n²)
// Worst Case (Reverse Sorted): O(n²)
//Reason → Two nested loops (n passes × up to n comparisons).

// Space Complexity
// O(1) (in-place sorting, no extra memory except a few variables).

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(v[j]>v[j+1])
            swap(v[j],v[j+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}