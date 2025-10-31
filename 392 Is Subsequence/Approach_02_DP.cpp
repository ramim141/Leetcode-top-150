// Approach 02: Recursion
// Time Complexity: O(2^(N+M)) in worst case
// Space Complexity: O(N+M) for recursion stack

#include <bits/stdc++.h>
using namespace std;

bool helper(int i, int j, string s, string t) {
    if (i == s.size()) return true;
    if (j == t.size()) return false;
    if (s[i] == t[j]) return helper(i + 1, j + 1, s, t);
    return helper(i, j + 1, s, t);
}
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return helper(0, 0, s, t);
    }

};