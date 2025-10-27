#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord_library(string s)
    {
        stringstream ss(s);
        string word;

        vector<string>words;

        while( ss >> word )
        {
            words.push_back(word);
        }

        if(words.size() == 0)
        {
            return 0;
        }
        return words.back().length();
    }
};