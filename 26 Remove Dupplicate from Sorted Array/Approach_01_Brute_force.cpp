// Approach 01: Using Extra Space (Set)
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;


int removeDuplicates_extra_space(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    set<int> unique_elements(nums.begin(), nums.end());

    int k = 0;
    for (int element : unique_elements) {
        nums[k] = element;
        k++;
    }
    
    return k;
}


int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates_extra_space(nums);
    
    cout << "The array after removing duplicates is: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nThe number of unique elements is: " << k << endl;

    return 0;
}