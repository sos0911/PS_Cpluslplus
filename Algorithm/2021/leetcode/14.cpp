#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        int minlen=INF;
        for(auto str : strs)
            minlen = min(minlen, (int)str.length());
        for(int i=0;i<minlen;i++){
            char cmp=strs[0][i];
            for(auto str : strs){
                if(str[i] != cmp)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, minlen);
    }
};