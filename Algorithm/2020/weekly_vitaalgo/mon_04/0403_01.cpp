// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	int len = input.size();
	int n;
	cin >> n;
	// dp[i][j] : ���̰� i�� �߽����� j�϶� �̰� ȸ���ΰ�?
	// ���̰� ¦��, Ȧ���϶� ����
	bool dp[1001][1001] = { false, };
	// ���� 1,2 precal
	for (int j = 0; j < len; j++)
		dp[1][j] = true;
	for (int i = 0; i < len - 1; i++)
		if (input[i] == input[i + 1])
			dp[2][i] = true;

	for (int i = 3; i < len; i++) {
		if (i % 2) {
			for (int j = 0; j < len; j++) {
				if (i - 2 >= 1 && dp[i - 2][j] && j - i / 2 >= 0 && j + i / 2 < len && input[j - i / 2] == input[j + i / 2]) {
					dp[i][j] = true;
				}
			}
		}
		else {
			for (int j = 0; j < len; j++) {
				if (i - 2 >= 1 && dp[i - 2][j] && j - i / 2 + 1 >= 0 && j + i / 2 < len && input[j - i / 2 + 1] == input[j + i / 2]) {
					dp[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		s--; e--;
		cout << dp[e - s + 1][(e + s) / 2] << '\n';
	}
	return 0;
}