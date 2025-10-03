// Problem Statement: Given a string, check whether it is a pangram 
// (contains all 26 English lowercase letters at least once).

// Time Complexity: O(n) (iterates through the string once to insert characters into a set,
// where n = length of the string)

// Space Complexity: O(1) (the set can contain at most 26 characters regardless of string length)

# include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    if (s.length()<26)
    {
        return false;
    } 
    set<char>c;
    for(char ch:s)
    {
        c.insert(ch);
    }
    if(c.size()<26)
    return false;
    else
    return true;
}
int main()
{
    string s;
    cin>>s;
    if(check(s))
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}