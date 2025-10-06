// Problem Statement: The code attempts to read n integers into a set and then erase all elements greater than or equal to 4
//  while printing elements. However, erasing elements from a set while iterating over it using a range-based
//   for loop leads to undefined behavior in C++.

// Time Complexity: O(n log n) for inserting n elements into the set + O(k log n) 
// for erasing elements (where k is the number of elements erased)

// Space Complexity: O(n) (the set stores all unique elements)

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        s.insert(x);
    }
    for(auto it = s.begin(); it != s.end(); ) {
        if(*it >= 4) it = s.erase(it);
        else ++it;
    }
    return 0;
}