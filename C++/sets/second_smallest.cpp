// Problem Statement: Given n integers, find the second smallest unique number in the input. Duplicate values are ignored.
// Time Complexity: O(n log n) (inserting n elements into a set, each insertion is O(log n))
// Space Complexity: O(n) (the set stores all unique elements)

//we have to print second smallest number in a vector or a series of elements taken 
// 5
// 3 5 1 2 1

// output-2


# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>s;
    for(int i=0;i<n;i++)
    {
        int d;cin>>d;
        s.push_back(d);
    }
    set<int>st;
    for(auto i:s)
    {
        st.insert(i);
    }
    auto itr=st.begin();
    itr++;
    cout<<"smallest second number "<<*itr;
    return 0;
}