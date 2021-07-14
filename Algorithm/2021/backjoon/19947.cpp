// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,y;
    cin>>h>>y;
    // 반복 동적 계획법 or 그래프(bfs)
    int dp[11];
    memset(dp, -1, sizeof(dp));
    dp[0] = h, dp[1] = h*1.05;
    int yearDiffs[3] = {1,3,5};
    float moneyDiffs[3] = {1.05, 1.2, 1.35};
    for(int i=2;i<=y;i++)
        for(int j=0;j<3;j++)
            dp[i] = i-yearDiffs[j]>=0? max(dp[i], (int)(dp[i-yearDiffs[j]]*moneyDiffs[j])) : dp[i];
    cout<<dp[y]<<'\n';
	return 0;
}