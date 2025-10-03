// Problem Statement
// Given a 3×4 binary matrix (each element is either 0 or 1), find the row that contains the maximum number of 1s.
// Input: a 3x4 matrix of 0s and 1s.
// Output: row index with the maximum number of 1s, and the count of 1s in that row.

// Time Complexity
// Outer loop runs over all rows: O(3)
// Inner loop runs over all columns: O(4)
// Total = O(rows × cols) = O(n × m)
// For a general n × m matrix: O(nm)

// Space Complexity
// Matrix of size 3×4 → constant space.
// Only uses a few integer variables (c, maxone, maxrows).
// Space = O(1) (constant).

# include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][4],i,j,c=0,maxone=0,maxrows=-1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }
    for ( i = 0; i < 3; i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==1)
            {
                c=4-j;
                if(c>maxone)
                {
                    maxone=c;
                    maxrows=i;
                }
                
            }
        }
    }
    cout<<"maximum no of ones is \n"<<maxone<<" \n in row \n"<<maxrows;    
    return 0;
}