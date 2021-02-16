#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // palindrom
        int len = s.length();
        string ans="";
        for(int i=0;i<len;i++){
            // 홀수길이
            int st=i, ed=i;
            while(st >= 0 && ed < len && s[st] == s[ed]){
                string cand = s.substr(st, ed-st+1);
                if(cand.length() > ans.length())
                    ans = cand;
                st--;
                ed++;
            }
            // 짝수길이
            int st=i, ed=i+1;
            while(st >= 0 && ed < len && s[st] == s[ed]){
                string cand = s.substr(st, ed-st+1);
                if(cand.length() > ans.length())
                    ans = cand;
                st--;
                ed++;
            }
        }
        return ans;
    }
};