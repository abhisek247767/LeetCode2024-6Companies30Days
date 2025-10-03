// Problem Statement: Given a 2D array and a rectangle defined by its top-left (l1, r1) 
// and bottom-right (l2, r2) coordinates, compute the sum of all elements within that rectangle.
// Time Complexity: O((l2 - l1 + 1) × (r2 - r1 + 1)) (nested loops over the submatrix)
// Space Complexity: O(1) (only uses integer variables sum, l1, r1, l2, r2; the input 2D vector is given)

# include<bits/stdc++.h>
using namespace std;
int recsum(vector<vector<int>>&v)
{
    int l1,r1,l2,r2,sum=0;
    cout<<"enter the values of l1,e1,l1,r2\n";
    cin>>l1>>r1>>l2>>r2; 
    for(int i=l1;i<=l2;i++)
    {
        for(int j=r1;j<=r2;j++)
        {
            sum+=v[i][j];
        }
    }
    return(sum);
}
int main()
{
    int n,m;
    cout<<"enter values of n and m \n";
    cin>>n>>m;
    cout<<"enter array elements\n";
    vector<vector<int>>vec(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
    int sum=recsum(vec);
    cout<<"sum of rectangle is \n"<<sum;
    return 0;
}