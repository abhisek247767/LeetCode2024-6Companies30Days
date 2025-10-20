// Problem Statement: Given two strings s and t, check whether they are anagrams of each other 
// (contain the same characters with the same frequency, order doesn’t matter).

// Time Complexity: O(n²) (nested loops used for sorting both strings manually, where n = length of the strings)

// Space Complexity: O(1) (sorting is done in-place using swaps; no extra data structures used)

# include<bits/stdc++.h>
using namespace std;
string check(string s,string t)
{
    if(s.size()!=t.size())
    return "no";
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            if(s[i]>s[j])
            {
                swap(s[i],s[j]);
            }
            if(t[i]>t[j])
            {
                swap(t[i],t[j]);
            }
        }
    }
    if(s==t)
    return "yes";
    else
    return "no";
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<check(s,t);
    return 0;
}