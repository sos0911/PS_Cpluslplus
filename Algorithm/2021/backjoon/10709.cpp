// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    int dp[101][101];
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<h;i++){
        string line;
        cin>>line;
        for(int j=0;j<w;j++)
            if(line[j] == 'c')
                dp[i][j] = 0;
    }
    // 내용 채우기
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(j-1>=0 && dp[i][j-1] != -1 && dp[i][j] == -1)
                dp[i][j] = dp[i][j-1] + 1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
	return 0;
}