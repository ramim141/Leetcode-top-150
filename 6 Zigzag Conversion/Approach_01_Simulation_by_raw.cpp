// Time Complexity: O(n), where n is the length of the input string s.
// Space Complexity: O(n), for storing the characters in the rows.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)
            return s;
        
        vector<string> raw(numRows, "");
        int curRow = 0;
        bool goingDown = false;

        for(char c: s)
        {
            raw[curRow] += c;
            if( curRow == 0 || curRow == numRows - 1 )
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string result = "";
        for(string r: raw)
            result += r;
        
        return result;
    }
};