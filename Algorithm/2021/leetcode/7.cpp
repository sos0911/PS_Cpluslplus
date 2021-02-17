#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        string num2str = to_string(abs(x));
        bool pos = x>=0? true:false;
        string intcmp = x >=0 ? to_string(INT_MAX):to_string(INT_MIN).substr(1);
        // 자리수 맞춰주기
        int diff = intcmp.length()-num2str.length();
        for(int i=0;i<diff;i++)
            num2str.push_back('0');
        // string 뒤집기
        std::reverse(num2str.begin(), num2str.end());
        cout<<num2str<<" "<<intcmp<<'\n';
        bool check = false;
        for(int i=0;i<intcmp.length();i++){
            if(!check && num2str[i] > intcmp[i])
                return 0;
            if(num2str[i] < intcmp[i])
                check = true;
        }
        string tmp = to_string(abs(x));
        if(!pos)
            tmp.push_back('-');
        std::reverse(tmp.begin(), tmp.end());
        int ans = stoi(tmp);
        return ans;
    }
};