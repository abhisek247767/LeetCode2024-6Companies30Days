// Problem Statement: Traverse or fill a square n × n matrix in a spiral order (top → right → bottom → left repeatedly).
//  In this code, the matrix elements are being read and incremented in a spiral-like iteration.
// Time Complexity: O(n²) (each element of the matrix is visited once in the spiral traversal)
// Space Complexity: O(1) (no extra space is used besides loop counters and indices; the input matrix is given)

# include<bits/stdc++.h>
using namespace std;
void spiralsq(vector<vector<int>>&v)
{
    int top=0;
    int bottom=v.size()-1;
    int left=0;
    int right=v[0].size()-1;
    int direction=0;
    int c=1;
    while(top<=bottom&&left<=right)
    {
        if(direction==0)
    {
        for(int i=left;i<=right;i++)
        {
            cin>>c;
            c++;
        }
        top++;
    }
    else if(direction==1)
    {
        for(int i=top;i<=bottom;i++)
        {
            cin>>c;
            c++;
        }
        right--;
    }
    else if(direction==2)
    {
        for(int i=right;i>=left;i--)
        {
            cin>>c;
            c++;
        }
        bottom--;
    }
    else
    {
        for(int i=bottom;i>=top;i--)
        {
            cin>>c;
            c++;
        }
        left++;
    }
    direction=(direction+1)%4;
    }
    cout<<"matrix is";
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cout<<"enter the value of n \n";
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    spiralsq(vec);
    return 0;
}