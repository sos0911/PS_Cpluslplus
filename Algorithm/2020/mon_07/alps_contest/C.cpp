// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200001];
const int mod = 1e9 + 7;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// pre-cal
	dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
	for (int i = 6; i <= 200000; i++) {
		dp[i] = dp[i - 2] + dp[i - 3] + dp[i - 4];
		dp[i] %= mod;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}
	return 0;
}