// Problem Statement: Given an array and a query with indices l and r, calculate the sum of 
// elements from index l to r (1-based indexing).
// Time Complexity: O(r) (iterates from 0 to r-1 to calculate total and prefix sums)
// Space Complexity: O(1) (only uses integer variables tsum, presum, and sum; the input vector is given)

# include<bits/stdc++.h>
using namespace std;
void sumofqueries(vector<int>&v)
{
    int tsum=0;
    int presum=0;
    cout<<"enter values of l and r\n";
    int l,r;
    cin>>l>>r;
    for(int i=0;i<r;i++)
    {
        tsum +=v[i];
        if(i<l-1)
        presum +=v[i];
    }
    cout<<tsum<<presum;
    int sum=tsum-presum;
    cout<<"\nsum of querie is \n"<<sum;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    cout<<"enter array elements\n";
    for(int i=1;i<=n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    sumofqueries(v);
    return 0;
}