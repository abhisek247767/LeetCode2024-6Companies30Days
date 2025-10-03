// Problem Statement: Given a 3×3 matrix, compute its transpose (swap rows with columns) and print the transposed matrix.
// Time Complexity: O(n²) (nested loops over all elements; here n = 3)
// Space Complexity: O(n²) (uses an extra matrix b of the same size to store the transpose)

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3],i,j,temp=0,b[3][3];
    cout<<"enter array elements\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            temp=a[i][j];
            b[j][i]=temp;
        }
    }
    cout<<"after transposing \n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<b[i][j];
        }
        cout<<"\n";
    }
    return 0;
}