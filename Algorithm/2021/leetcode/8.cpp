#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int myAtoi(string s) {
        // 부호 cache
        bool positive = true;
        int len = s.length();
        int stidx=-1, edidx=-1;
        for(int i=0;i<len;i++){
            if(s[i] >= '0' && s[i] <= '9'){
                stidx = i;
                break;
            }
            else if(s[i] != ' ' && s[i] != '-' && s[i] != '+')
                return 0;
            else if(s[i] == '-' || s[i]=='+'){
                if(s[i]=='-')
                    positive = false;
                stidx=i+1;
                if(!(s[stidx] >= '0' && s[stidx] <= '9'))
                    return 0;
                break;
            }
        }
        if(stidx==-1)
            return 0;
        // stidx부터 시작
        for(int i=stidx;i<len;i++){
            if(!(s[i] >= '0' && s[i] <= '9')){
                edidx=i-1;
                break;
            }
        }
        if(edidx==-1)
            edidx=len-1;
        // clamp
        string clampstr = positive? to_string(abs((ll)INT_MAX)) : to_string(abs((ll)INT_MIN));
        string num2str = s.substr(stidx, edidx-stidx+1);
        string temp;
        int len1 = clampstr.length(), len2 = num2str.length();
        // 한 자리씩 비교
        if(len1 > len2)
            num2str = temp.assign(len1-len2, '0') + num2str;
        else if(len2 > len1)
            clampstr = temp.assign(len2-len1, '0') + clampstr;
        bool check = false;
        for(int i=0;i<clampstr.length();i++){
            if(clampstr[i] > num2str[i])
                check = true;
            if(!check && clampstr[i] < num2str[i])
                return (positive? INT_MAX : INT_MIN);
        }
        int ans = positive? stoi(s.substr(stidx, edidx-stidx+1)) : stoi("-" + s.substr(stidx, edidx-stidx+1));
        return (int)ans;
    }
};