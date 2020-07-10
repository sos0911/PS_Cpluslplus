// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inputarr[200021];
// �ƹ��� Ŀ���� 4��
ll tree[800084];
ll init(int node, int st, int ed) {
	// (st,ed)������ tree[node]�� ���
	if (st == ed)
		return tree[node] = inputarr[st];
	else
		return tree[node] = init(node * 2, st, (st + ed) / 2) + init(node * 2 + 1, (st + ed) / 2 + 1, ed);
}
ll query(int node, int st, int ed, int left, int right) {
	// (left,right) => ã�� ����
	if (left > ed || right < st)
		return 0;
	if (left <= st && ed <= right)
		return tree[node];
	return query(node * 2, st, (st + ed) / 2, left, right) + query(node * 2 + 1, (st + ed) / 2 + 1, ed, left, right);
}
void update(int node, int st, int ed, int idx, ll diff) {
	// idx : ������ �� idx
	// diff : ����� �� ��
	if (idx < st || idx > ed)
		return;
	tree[node] += diff;
	if (st != ed) {
		update(node * 2, st, (st + ed) / 2, idx, diff);
		update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, diff);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ���� or segment tree
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> inputarr[i];
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			cout << query(1, 1, n, b, c) << '\n';
		else
			update(1, 1, n, b, c - inputarr[b]);
	}
	return 0;
}