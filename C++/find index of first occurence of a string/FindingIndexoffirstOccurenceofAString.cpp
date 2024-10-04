#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};