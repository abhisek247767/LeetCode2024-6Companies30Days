// Problem Statement: Read n integers and store them in an unordered_set to remove duplicates, 
// then print the unique elements in arbitrary order.

// Time Complexity: O(n) on average (each insertion into an unordered_set is O(1) on average)

// Space Complexity: O(n) (the unordered_set stores up to n unique elements)

# include<bits/stdc++.h>
using namespace std;
//in unordered set elements are stored in unordered set
// 1 2 6 4 2
// 4 2 6 1 
int main()
{
    int n;cin>>n;
    unordered_set<int>us;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        us.insert(x);
    }
    for(auto i:us)
    {
        cout<<i<<" ";
    }
    return 0;
}