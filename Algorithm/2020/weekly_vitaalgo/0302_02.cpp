// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
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
	// ����� i���϶� ������ ȭ���� j�� ������.
	// j = 0,9�϶� ����ó��
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