#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // string으로 변환 말고 풀어보자.
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x!=0))
            return false;
        // 양수
        // 뒤 반절만 reverse해본다.
        int rev = 0;
        while(x > rev){
            rev = rev*10 + (x%10);
            x/=10;
        }
        // 자리수가 홀수일 때 예외처리
        return (rev/10 == x) || (rev==x);
    }
};
