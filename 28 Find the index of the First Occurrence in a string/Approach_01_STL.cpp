// Time Complexity: O((N - M) * M) in worst case, where N is the length of haystack and M is the length of needle.
// Space Complexity: O(1), as no extra space is used.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirstOccurrence(string haystack, string needle)
    {

        if (needle.empty())
            return 0;


        size_t found_pos = haystack.find(needle);
        if (found_pos != std::string::npos)
        {
            return static_cast<int>(found_pos);
        }
        return -1;
    }
};