// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
#define SIZE 202020
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

//vvi adj(SIZE, vi());
//vb group(SIZE, false);
vector<int> adj[SIZE];
bool group[202020] = { false, };

int dfs(int idx) {
	// idx : ��� idx
	// gidx ; �׷� idx
	if (group[idx])
		return 0;
	group[idx] = true;
	int num = 1;
	for (int i = 0; i < adj[idx].size(); i++)
		num += dfs(adj[idx][i]);
	return num;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// dfs
	int ans = 0, ansidx = -1;
	for (int i = 1; i < n + 1; i++) {
		int ret = dfs(i);
		if (ret > ans) {
			ansidx = i;
			ans = ret;
		}
	}
	cout << ansidx << " " << ans << '\n';
	return 0;
}