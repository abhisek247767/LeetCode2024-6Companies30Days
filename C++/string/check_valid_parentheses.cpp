// Problem Statement: Given a string containing parentheses '()', brackets '[]', and braces '{}',
//  check whether the string is balanced (every opening bracket has a corresponding closing bracket in the correct order).

// Time Complexity: O(n) (iterate through all characters of the string once, where n = length of the string)

// Space Complexity: O(n) (stack may store all opening brackets in the worst case)

# include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
     stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('|s[i]=='['||s[i]=='{')
            st.push(s[i]);
            else
            {if(st.empty())
            return false;
            char c=st.top();st.pop();
            if(s[i]==')'&&c!='(')
            return false;
            if(s[i]==']'&&c!='[')
            return false;
            if(s[i]=='}'&&c!='{')
            return false;}
        }
        if(st.empty())
        return true;
        else
        return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}