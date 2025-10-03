// Problem Statement: Read n strings, store them in a set to automatically remove duplicates and 
// sort them in lexicographical order, then print the sorted unique strings.

// Time Complexity: O(n log n) (inserting n strings into the set, each insertion is O(log n))

// Space Complexity: O(n) (the set stores up to n unique strings)

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter thr values of n"<<"\n";
    cin>>n;
    set<string>s;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.insert(str);
    }
    for(auto str:s)
    {
        cout<<str<<" ";
    }
}