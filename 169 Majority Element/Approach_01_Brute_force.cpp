// Approach 1: Brute Force
// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                    count++;
            }
            if (count > n / 2)
                return nums[i];
        }
        return -1; // This line will never be reached as per problem constraints    
    }
};