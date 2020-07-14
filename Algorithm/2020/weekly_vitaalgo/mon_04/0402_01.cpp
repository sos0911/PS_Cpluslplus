// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100001];
struct node {
	// ������� �� d,p�� 0���� �ڵ� �ʱ�ȭ
	int d, p;
};
node info[100001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// lca
	// dp ���x ����.
	// �ܼ��� Ʈ�� ������� �Է¹޾Ƽ� ���� �ø���.
	// �� ��帶�� ���̿� �θ� ���� �����ؾ� �Ѵ�.
	// adj ����� bfs or dfs�� �� ���� ����
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// bfs
	// (��� idx)
	// root node�� ���̴� 1
	queue<int> bfsq;
	bool visitarr[100001] = { false, };
	bfsq.push(1);
	visitarr[1] = true;
	info[1].d = 1;
	while (!bfsq.empty()) {
		int curnode = bfsq.front();
		bfsq.pop();
		for (auto node : adj[curnode])
			if (!visitarr[node]) {
				bfsq.push(node);
				visitarr[node] = true;
				info[node].d = info[curnode].d + 1;
				info[node].p = curnode;
			}
	}
	int a, b;
	cin >> a >> b;
	// ���̸� ���� ������ ������
	if (info[a].d < info[b].d)
		swap(a, b);
	if (info[a].d != info[b].d)
		while (info[a].d != info[b].d)
			a = info[a].p;


	// ���� ���ÿ� 1�� ���� �ö�
	while (a != b) {
		a = info[a].p;
		b = info[b].p;
	}
	cout << a << '\n';
	return 0;
}