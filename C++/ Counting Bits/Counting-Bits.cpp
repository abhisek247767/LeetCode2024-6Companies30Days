#include <iostream>
using namespace std;
int count(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
vector<int> countBits(int n)
{
    vector<int> ans;
    int i = 0;
    while(i <= n){
        ans.push_back(count(i));
        i++;
    }
    return ans;
}
int main()
{
    vector<int> ans = countBits(2);
    cout << "Counting Bits : " << endl;
    for(auto n :ans) cout<<n<<" ";
    cout<<endl;
    return 0;
}