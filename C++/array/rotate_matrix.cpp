// Problem Statement: Given an n × n matrix, rotate it 90 degrees clockwise in-place.
// Time Complexity: O(n²) (nested loops for transposing and then reversing each row)
// Space Complexity: O(1) (rotation is done in-place using swaps; no extra matrix is used)

# include<bits/stdc++.h>
using namespace std;
void rotatearr(vector<vector<int>>&v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(v[i][j],v[j][i]);

        }
    }
    for(int i=0;i<n;i++)
    {
         reverse(v[i].begin(),v[i].end());
    }
   
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
    rotatearr(vec);
    cout<<"after rotating \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
    return 0;
}