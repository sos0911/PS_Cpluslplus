#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string num2str = to_string(num);
        int len = num2str.length();
        string temp = "1", temp2="";
        int div = stoi(temp + temp2.assign(len-1, '0'));
        // 앞에서부터 차례대로.
        vector<vector<char>> characters(5, vector<char>());
        characters[1].push_back('I');
        characters[1].push_back('V');
        characters[2].push_back('X');
        characters[2].push_back('L');
        characters[3].push_back('C');
        characters[3].push_back('D');
        characters[4].push_back('M');
        string ans="";
        while(num > 0){
            if(num/div == 4){
                ans += characters[len][0];
                ans += characters[len][1];
            }
            else if(num/div==9){
                ans += characters[len][0];
                ans += characters[len+1][0];
            }
            else if(num/div < 5)
                for(int i=0;i<num/div;i++)
                    ans += characters[len][0];
            // 5 이상
            else{
                ans += characters[len][1];
                for(int i=5;i<num/div;i++)
                    ans += characters[len][0];
            }
            num -= div*(num/div);
            div /= 10;
            len--;
            cout<<num<<'\n';
        }
        return ans;
    }
};