// Approach 02: Using Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int k = 2;
    for(int i = 2; i < nums.size(); ++i) {
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
        
    }
    
    return k;
}
int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int new_length = removeDuplicates(nums);
    
    cout << "New length: " << new_length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < new_length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}