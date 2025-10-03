// Problem Statement: Read n integers, store them in a multiset (which allows duplicates) and
//  print the elements in ascending order. Optionally, the multiset can be declared with 
//  greater<int> to print in descending order.

// Time Complexity: O(n log n) (each insertion into the multiset takes O(log n))

// Space Complexity: O(n) (stores all n elements, including duplicates)

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    multiset<int>m;
    //if we want to get output in decending order we write kyeword greater
    // multiset<int. greater<int>>m;
    //in multiset we can store duplicate number or char in set
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m.insert(x);
    }
    for(auto i:m)
    {
        cout<<i<<" ";
    }
    return 0;
}