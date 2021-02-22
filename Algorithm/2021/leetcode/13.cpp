#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        // 4x, 9x만 예외처리
        // 기본적으로 쓰는 순서가 큰 숫자가 먼저 등장함
        map<char, int> value;
        value.insert({'I', 1});
        value.insert({'V', 5});
        value.insert({'X', 10});
        value.insert({'L', 50});
        value.insert({'C', 100});
        value.insert({'D', 500});
        value.insert({'M', 1000});
        map<string,int> except;
        except.insert({"IV", 4});
        except.insert({"IX", 9});
        except.insert({"XL", 40});
        except.insert({"XC", 90});
        except.insert({"CD", 400});
        except.insert({"CM", 900});
        int len = s.length(), ans = 0;
        int idx=0;
        while(idx < len-1){
            // 2개씩 볼 것
            if(value[s[idx]] < value[s[idx+1]]){
                ans += except[s.substr(idx,2)];
                idx+=2;
            }
            else{
                ans += value[s[idx]];
                idx++;
            }
        }
        if(idx==len-1)
            ans += value[s[idx]];
        return ans;
    }
};