// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	const int mod = 1e9;
	int n;
	cin >> n;
	int dp[101][10] = { 0, };
	// dp[i][j]
	// 사람이 i명일때 마지막 화음이 j인 가짓수.
	// j = 0,9일때 예외처리
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++)
				dp[i][j] = 1;
			continue;
		}
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (int)(((ll)dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod);
		}
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];
	cout << ans << '\n';
	return 0;
}