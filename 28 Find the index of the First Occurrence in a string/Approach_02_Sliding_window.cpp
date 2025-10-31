// Approach 02: Sliding Window
// Time Complexity: O(N * M) in the worst case, where N is the length of haystack and M is the length of needle.
// Space Complexity: O(1), as no extra space is used.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirstOccurrence(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;
        if (n < m)
            return -1;

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};