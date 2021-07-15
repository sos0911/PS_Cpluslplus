// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1, -1);
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 5;
	for(int i=5;i<=n;i++)
		dp[i] = (dp[i-3]*2 + dp[i-4] + dp[i-2])%10;
	cout<<dp[n]<<'\n';
	return 0;
}