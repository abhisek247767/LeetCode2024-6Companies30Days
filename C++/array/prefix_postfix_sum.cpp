// Problem Statement: Given an array, check if there exists an index where the sum of elements before it is equal
//  to the sum of elements after it (prefix sum equals postfix sum). 
//  Returns true if such an index exists, otherwise false.

// Time Complexity: O(n) 
// (one pass to compute total sum, one pass to check prefix vs postfix)

// Space Complexity: O(1) 
// (only uses integer variables sum and prefix; the input vector is given)

# include<bits/stdc++.h>
using namespace std;
bool sumprefixpostfix(vector<int>&v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
        sum+=v[i];
        cout<<sum<<"\n";
        int prefix=0;
        for(int i=0;i<v.size();i++)
        {
            prefix +=v[i];
            int postfix = sum-prefix;
            if(prefix==postfix)
            return true;
            
        }
        return false;
}
int main()
{
    int n;
    cin>>n;
    cout<<"enter array elements";
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<sumprefixpostfix(v);
    return 0;
}