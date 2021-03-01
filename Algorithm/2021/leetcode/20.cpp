#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        int len = s.length();
        vector<char> left = {'(', '{', '['}, right = {')', '}', ']'};
        for(int i=0;i<len;i++){
            bool check=false;
            for(int j=0;j<right.size();j++){
                if(s[i] == right[j]){
                    check=true;
                    if(container.size() && container.top() == left[j]){
                        container.pop();
                        break;
                    }
                    else
                        return false;
                }
            }
            if(!check)
                container.push(s[i]);
        }
        return (container.size()? false : true);
    }
};