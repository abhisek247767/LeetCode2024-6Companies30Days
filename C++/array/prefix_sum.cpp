// Problem Statement: Given an array, compute the prefix sum sequentially by adding each element to 
// the sum of previous elements. (However, in this code, the vector itself is not updated; 
//     only a cumulative sum variable c is computed.)

// Time Complexity: O(n) 
// (single pass through the array for computing the cumulative sum)
// Space Complexity: O(1) 
// (only uses integers sum and c; the input vector is given)

# include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,sum=0;
    cin>>n;
    
    vector<int>v;
    cout<<"enter array elements\n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }cout<<"elements are ";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    int c=v[0];
    for(int i=1;i<v.size();i++)
    {
        sum=c+v[i];
        c=sum;
    }
    cout<<"after prefixing\n";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}