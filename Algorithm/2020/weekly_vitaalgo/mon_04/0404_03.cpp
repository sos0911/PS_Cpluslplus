// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// lcs�� �����
	// cost[i][j] : a�� i��° ����, b�� j��° ���ڱ��� ���� ���� ���ߴ� �ּ� cost
	int cost[1001][1001] = { 0, };
	// �ʱ�ȭ
	for (int i = 1; i <= m; i++)
		cost[0][i] = i;
	for (int i = 1; i <= n; i++)
		cost[i][0] = i;
	// ����
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1])
				cost[i][j] = cost[i - 1][j - 1];
			else
				cost[i][j] = min({ cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1] }) + 1;
	cout << cost[n][m] << '\n';
	return 0;
}