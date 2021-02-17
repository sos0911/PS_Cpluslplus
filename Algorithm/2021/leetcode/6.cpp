#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        // numrows : 지그재그 포맷 유지할 row 수
        vector<vector<char>> cache(numRows, vector<char>());
        int len = s.length(), currow = 0;
        bool upstair = true; // false면 내려가는 중
        for(int i=0;i<len;i++){
            cache[currow].push_back(s[i]);
            if(currow == numRows-1 || currow == 0)
                upstair = !upstair;
            currow = upstair? max(currow-1, 0):min(currow+1, numRows-1);
        }
        string ans="";
        for(int i=0;i<numRows;i++)
            for(int j=0;j<cache[i].size();j++)
                ans.push_back(cache[i][j]);
        return ans;
    }
};