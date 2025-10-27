// Approach 02: Using Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    
    if (nums.empty()) {
        return 0;
    }

    int k = 1; // ইউনিক উপাদানের সংখ্যা
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    
    cout << "The array after removing duplicates is: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nThe number of unique elements is: " << k << endl;

    return 0;
}