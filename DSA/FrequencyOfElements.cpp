#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={1,2,2,3,1,4,2};
    unordered_map<int,int> freq;
    for(int x:nums) freq[x]++;
    for(auto &p:freq) cout<<p.first<<" -> "<<p.second<<"\n";
    return 0;
}

