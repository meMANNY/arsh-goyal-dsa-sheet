
#include <string>

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t found = haystack.find(needle);
        return (found != -1) ? static_cast<int>(found) : -1;
    }
};