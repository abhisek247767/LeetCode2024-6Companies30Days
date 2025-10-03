// Problem Statement: Given an n × m matrix, print its elements in spiral order starting from the top-left corner
//  and moving clockwise (top → right → bottom → left repeatedly).
// Time Complexity: O(n × m) (each element of the matrix is visited exactly once)
// Space Complexity: O(1) (only uses loop counters and boundary indices; no extra space besides the input matrix)

# include<bits/stdc++.h>
using namespace std;
void spiral(vector<vector<int>>&v)
{
    int top=0;
    int bottom=v.size()-1;
    int left=0;
    int right=v[0].size()-1;
    int direction=0;
    while(top<=bottom&&left<=right)
    {
        if(direction==0)
    {
        for(int i=left;i<=right;i++)
        {
            cout<<v[top][i];
        }
        top++;
    }
    else if(direction==1)
    {
        for(int i=top;i<=bottom;i++)
        {
            cout<<v[i][right];
        }
        right--;
    }
    else if(direction==2)
    {
        for(int i=right;i>=left;i--)
        {
            cout<<v[bottom][i];
        }
        bottom--;
    }
    else
    {
        for(int i=bottom;i>=top;i--)
        {
            cout<<v[i][left];
        }
        left++;
    }
    direction=(direction+1)%4;
    }
}
int main()
{
    int n,m;
    cout<<"enter values of n and m \n";
    cin>>n>>m;
    vector< vector<int>>vec(n,vector<int>(m));
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
    spiral(vec);

    
    return 0;
}