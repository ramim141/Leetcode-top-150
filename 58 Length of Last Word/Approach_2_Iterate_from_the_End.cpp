#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
            i--; // skip trailing spaces
        while (i >= 0 && s[i] != ' ')
        { // count the length of the last word
            len++;
            i--;
        }
        return len;
    }
};