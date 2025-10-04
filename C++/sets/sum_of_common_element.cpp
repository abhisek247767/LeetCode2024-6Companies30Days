// Problem Statement: Given two arrays, find the sum of all elements that are common to both arrays.

// Time Complexity: O(n log n + m log n) (inserting n elements of the first array into a 
//     set takes O(n log n), then searching m elements from the second array in the set takes O(m log n))

// Space Complexity: O(n) (the set stores all unique elements from the first array)

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,sum=0;
    cin>>n>>m;
    vector<int>v1(n);
    vector<int>v2(m);
    for(int i=0;i<n;i++)
    cin>>v1[i];
    for(int i=0;i<m;i++)
    cin>>v2[i];
    set<int>s1;
    for(auto i:v1)
    s1.insert(i);
    for(auto j:v2)
    {
        if(s1.find(j)!=s1.end())
        {
            sum+=j;
        }
    }
    cout<<sum;
    return 0;
}