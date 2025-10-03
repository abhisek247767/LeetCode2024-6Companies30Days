// Problem Statement: Given a string, check whether it is a palindrome, ignoring 
// non-alphanumeric characters and case differences.

// Time Complexity: O(n) (two-pointer traversal of the string once, where n = length of the string)

// Space Complexity: O(1) (only integer variables a and l are used; no extra data structures)

# include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int a=0,l=s.size()-1;
    while(a<l)
    {
        if(!isalnum(s[a]))
        a++;
        else if(!isalnum(s[l]))
        l--;
        else if(tolower(s[a])!=tolower(s[l]))
        return false;
        else{
            a++;
            l--;
        }
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}