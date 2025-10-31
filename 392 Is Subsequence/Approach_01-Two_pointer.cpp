// Approach 01: Two pointer
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i = 0;
       int j = 0;
       while(i < s.size() && j < t.size())
       {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
       }
       return i == s.size();
    }
};