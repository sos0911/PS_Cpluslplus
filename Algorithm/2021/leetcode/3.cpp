#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int st=0, ed=0;
        // set or vector?
        set<char> cnt;
        int ans=0;
        while(ed < len){
            while(cnt.find(s[ed]) != cnt.end()){
                // 자료구조 갱신
                cnt.erase(s[st]);
                st++;
            }
            ans = max(ans, ed-st+1);
            cnt.insert(s[ed]);
            ed++;
        }
        return ans;
    }
};