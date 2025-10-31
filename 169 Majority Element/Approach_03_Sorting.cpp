// Approach 03: Sorting
// Time Complexity: O(N log N)
// Space Complexity: O(1) or O(N) depending on the sorting algorithm used

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};