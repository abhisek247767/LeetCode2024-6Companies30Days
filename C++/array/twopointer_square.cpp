// Problem Statement: Given an array, compute the square of each element and then sort the 
// squared values in non-decreasing order.
// Time Complexity: O(n²) (computing squares is O(n), sorting using nested loops is O(n²))
// Space Complexity: O(n) (an extra vector a is used to store the squared values)

# include<bits/stdc++.h>
using namespace std;
void square(vector<int>&v)
{
    vector<int>a(v.size());
    for(int i=0;i<v.size();i++)
    {
        a[i]=v[i]*v[i];
    }
    cout<<"before sorted\n";
    for(int i=0;i<v.size();i++)
    cout<<a[i]<<" ";
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(a[i]>a[j])
            {
                int c=a[i];
            a[i]=a[j];
            a[j]=c;
            }
            
        }
    }
    cout<<"\n after sorted\n";
    for(int i=0;i<v.size();i++)
    cout<<a[i]<<" ";

}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    square(v);
    return 0;
}