// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
#define INF 1e9
#define SIZE 16
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
vvi adj;
int n;
// �������� ���������� �߿����� �ʴ�.
// �������� �׻� idx 0���� �����Ѵ�.
// dp[i][j] : bitmask i �湮���� �� (j) ����, ���� j�� �湮������ �� ���¿��� �������� ���� cost.
int dp[1 << (SIZE)][SIZE];
int solve(int idx, int visit) {
	cout << "idx : " << idx << " visit : " << bitset<17>(visit) << '\n';
	// edge cost=0�̸� ��������
	// visit�� bitmask�� �ؾ��Ѵ�.
	// 16�̴� 2^16.. int������ ���
	if ((1 << (n + 1)) - 1 == visit)
		return adj[idx][0] ? adj[idx][0] : INF;
	int& ret = dp[visit][idx];
	if (ret != INF)
		return ret;
	for (int i = 0; i < n; i++)
		if (!(visit & (1 << i)) && adj[idx][i])
			ret = min(ret, solve(i, visit | (1 << i)) + adj[idx][i]);
	return ret;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// dfs�� ����
	cin >> n;
	adj = vvi(n, vi(n, -1));
	for (int i = 0; i < (1 << SIZE); i++)
		fill(dp[i], dp[i] + SIZE, INF);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	int ans = solve(0, 1 << 0);
	cout << (ans == INF? 0 : ans) << '\n';
	return 0;
}