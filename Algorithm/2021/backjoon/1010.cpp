// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j){
    return i>=0 && j>=0 && i>=j;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int noft;
    cin>>noft;
    // 한꺼번에 계산하기
    // iCj
    int dp[31][31];
    memset(dp, -1, sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=30;i++)
        for(int j=0;j<=i;j++)
            dp[i][j] = (check(i-1,j-1)? dp[i-1][j-1] : 0) + (check(i-1,j)? dp[i-1][j] : 0);
    for(int i=0;i<noft;i++){
        int n,m;
        cin>>n>>m;
        cout<<dp[m][n]<<'\n';
    }
	return 0;
}