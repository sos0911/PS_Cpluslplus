#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<vector<char>> mapping;
    string cand;
    string digits;
    
    void make_permutation(int idx){
        // 순열을 재귀로 만든다.
        // idx : 지금 결정해야 하는 idx
        // c++ string은 배열처럼 사용 가능하며 배열처럼 동작 가능
        if(idx == digits.length()){
            ans.push_back(cand);
            return;
        }

        int map_idx = digits[idx] - '0';
        for(int i=0;i<mapping[map_idx].size();i++){
            cand[idx] = mapping[map_idx][i];
            make_permutation(idx+1);   
        }
    }
    vector<string> letterCombinations(string digits) {

        this->digits = digits;

        mapping.assign(10, vector<char>());
        mapping[2]= {'a','b','c'};
        mapping[3]= {'d','e','f'};
        mapping[4]= {'g','h','i'};
        mapping[5]= {'j','k','l'};
        mapping[6]= {'m','n','o'};
        mapping[7]= {'p','q','r','s'};
        mapping[8]= {'t','u','v'};
        mapping[9]= {'w','x','y','z'};
        int len = digits.length();
        cand.assign(len, '0');

        if(!len)
            return ans;
        make_permutation(0);
        return ans;
    }
};