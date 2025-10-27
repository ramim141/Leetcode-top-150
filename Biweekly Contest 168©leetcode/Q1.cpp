/*
You are given a string s of length n consisting of lowercase English letters.

You must perform exactly one operation by choosing any integer k such that 1 <= k <= n and either:

reverse the first k characters of s, or
reverse the last k characters of s.
Return the lexicographically smallest string that can be obtained after exactly one such operation.

A string a is lexicographically smaller than a string b if, at the first position where they differ, a has a letter that appears earlier in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters are the same, then the shorter string is considered lexicographically smaller.©leetcode
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string forward_string(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s;
    }

    string backward_string(string s, int k) {
        reverse(s.end() - k, s.end());
        return s;
    }

    string lexSmallest(string s) {
        string ans = s;
        int n = s.size();

        for (int k = 1; k <= n; k++) {
            string temp = forward_string(s, k);
            if (temp < ans) ans = temp;

            string temp2 = backward_string(s, k);
            if (temp2 < ans) ans = temp2;
        }

        return ans; 
    }
};


int main() {
    Solution sol;
    string s = "dcab";
    cout << sol.lexSmallest(s) << endl; // Output: "acb"
    return 0;
}