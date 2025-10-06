// Problem Statement: Given two strings s1 and s2, check if there exists a one-to-one character 
// mapping from s1 to s2. If such a mapping is possible for all characters, return "yes", 
// otherwise return "no".

// Time Complexity: O(n) (iterate through all characters of s1 once, with map operations taking O(log n) each in the worst case)

// Space Complexity: O(n) (map stores at most n character mappings)

# include<bits/stdc++.h>
using namespace std;
string check(string s1,string s2)
{
    map<char,char>m;
    if(s1.size()==s2.size())
    return "no";
        for(int i=0;i<s1.size();i++)
        {
            if(m.find(s1[i])!=m.end())
            {
                if(s1[i]!=s2[i])
                return "no";
            }
            else
            m.insert(make_pair(s1[i],s2[i]));
        }
    return "yes";
}
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<check(s1,s2);
    
    return 0;
}