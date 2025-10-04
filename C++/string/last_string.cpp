// Problem Statement: Given a string, remove all spaces, store the remaining characters in a vector,
//  print each character, and return the count of non-space characters.

// Time Complexity: O(n) (iterate through all characters of the string once, where n = length of the string)

// Space Complexity: O(n) (vector stores all non-space characters)

# include<bits/stdc++.h>
using namespace std;
int check(string s)
{
    vector<char>v;
    int k=0;
    for( auto i:s)
    {
        if(i!=' ')
        v.push_back(i);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
        k++;
    }
    return k;
}
int main()
{
    string s;
    cin>>s;
    cout<<"\n"<<check(s);
    return 0;
}