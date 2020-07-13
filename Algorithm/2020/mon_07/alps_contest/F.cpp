// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int b_n[6], b_c[6]; // ���� ����, ��ġ���
int noft[6];
const int INF = 1e9;
int mincost=INF;
int n, k;
// �ش� cost�� �ذ��ϴ� ������.
int nofcost[51] = { 0, };

void solve(int left, int cost, int lastidx, int nofb) {
	// ���� �������� : left, ������ ��� ��� idx : lastidx
	// ��� ��� �� : nofb
	if (left <= 0 && nofb <= n) {
		mincost = min(mincost, cost);
		nofcost[cost]++;
		return;
	}
	if (nofb >= n)
		return;
	for (int i = lastidx; i < k; i++)
		solve(left - b_n[i], cost + b_c[i], i, nofb + 1);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ���Ʈ������ �׳� ã�ƺ���..
	// ������ ���� ������.
	// ������ ã�ƺ� ������ ���ƺ��� 5^5..
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> noft[i];
	for (int i = 0; i < k; i++)
		cin >> b_n[i] >> b_c[i];
	for (int i = 0; i < n; i++) {
		solve(noft[i], 0, 0, 0);
		cout << mincost<<" "<< nofcost[mincost] << '\n';
		mincost = INF;
		memset(nofcost, 0, sizeof(nofcost));
	}
	return 0;
}