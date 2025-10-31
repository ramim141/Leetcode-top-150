// Approach 04: Boyer-Moore Voting Algorithm
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int count = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};