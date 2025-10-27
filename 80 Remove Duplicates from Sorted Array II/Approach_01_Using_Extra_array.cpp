// Approach 01: Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates_extra_space(vector<int>& nums) {
    if (nums.size() <= 2) {
        return nums.size();
    }

    vector<int> result;
    for (int num : nums) {
        if (result.size() < 2 || num != result[result.size() - 2]) {
            result.push_back(num);
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        nums[i] = result[i];
    }

    return result.size();
}