// Approach 02: Hash map
// Time Complexity: O(N)
// Space Complexity: O(N)


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freqMap;
        int n = nums.size();

        // Count the frequency of each element
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // Find the element with frequency greater than n/2
        for (const auto &pair : freqMap)
        {
            if (pair.second > n / 2)
            {
                return pair.first;
            }
        }

        return -1; // This line will never be reached as per problem constraints
    }
};