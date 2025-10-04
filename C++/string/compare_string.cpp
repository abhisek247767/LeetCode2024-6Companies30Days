// Problem Statement: Given two strings s and q, find the first occurrence of string q in s 
// and return its starting index. If q is not present in s, return -1.

// Time Complexity: O(m × n) in the worst case (for each character in s of length m,
//      the substring comparison with q of length n may take O(n))

// Space Complexity: O(1) (only integer variables are used; no extra space proportional to input size)

# include<bits/stdc++.h>
using namespace std;
int check(string s,string q)
{
    int n=q.size();
    int m=s.size();
    if(n>m)
    return -1;
    for(int i=0;i<m;i++)
    {
        if(s[i]==q[0])
        {
            if(s.substr(i,n)==q)
            return i;
        }
    }
    return -1;
}
int main()
{
    string s,q;
    cin>>s>>q;
    cout<<check(s,q);
    return 0;
}