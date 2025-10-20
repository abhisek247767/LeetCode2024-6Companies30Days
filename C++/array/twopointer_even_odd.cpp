// Problem Statement: Given an array of 5 integers, rearrange the array so that all even numbers come before
//  odd numbers while preserving relative order among swapped elements.
// Time Complexity: O(n²) (nested loops over the array; here n = 5)
// Space Complexity: O(1) (rearrangement is done in-place; no extra data structures are used)

# include<bits/stdc++.h>
using namespace std;
void check(vector<int>&a)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[i]%2==1&&a[j]%2==0)
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
    vector<int>a(5);
    cout<<"enter array element  \n ";
    for(int i=0;i<5;i++)
    cin>>a[i];
    check(a);
    cout<<"after sorting \n";
    for(int i=0;i<5;i++)
    cout<<a[i];
    return 0;

}