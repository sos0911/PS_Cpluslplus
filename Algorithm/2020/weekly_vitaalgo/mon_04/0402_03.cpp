// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100001];
// p[i][j] : node i의 2^j번째 부모
// 어떤 노드의 p[i][j]는 p[i][j-1] -> p[i][j-1];
int p[100001][20] = { 0, };
int d[100001]; // 깊이 저장

int PMAX;

int LCA(int a, int b) {
	// a,b의 lca 리턴
	if (d[a] < d[b])
		swap(a, b);

	// 깊이를 맞춰 준다.
	if (d[a] != d[b])
		for (int j = PMAX; j >= 0; j--)
			if (d[a] - (1 << j) >= d[b])
				a = p[a][j];

	// 만약 a==b면 답을 찾음
	if (a == b)
		return a;

	for (int j = PMAX; j >= 0; j--) {
		// p[a][j] = p[b][j]가 될때 중단시켜 버리면 이게 LCA인지는 모른다.
		if (d[a] - (1 << j) > 0 && p[a][j] != p[b][j]) {
			a = p[a][j];
			b = p[b][j];
		}
	}
	return p[a][0];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// lca
	// p 사용 버전.

	// 각 노드마다 깊이와 부모 노드는 유지해야 한다.
	// adj 만들고 bfs or dfs로 위 정보 수집
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// bfs
	// (노드 idx)
	// root node의 깊이는 1
	queue<int> bfsq;
	bool visitarr[100001] = { false, };
	bfsq.push(1);
	visitarr[1] = true;
	d[1] = 1;
	while (!bfsq.empty()) {
		int curnode = bfsq.front();
		bfsq.pop();
		for (auto node : adj[curnode])
			if (!visitarr[node]) {
				bfsq.push(node);
				visitarr[node] = true;
				d[node] = d[curnode] + 1;
				p[node][0] = curnode;
			}
	}

	int rep = 0;
	while ((1 << rep) < n)
		rep++;
	PMAX = rep;

	// p 완성
	for (int j = 1; (1 << j) < n; j++)
		for (int i = 1; i <= n; i++)
			if (p[i][j - 1])
				p[i][j] = p[p[i][j - 1]][j - 1];

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int lca = LCA(a, b);
		if (LCA(lca, c) == lca && (LCA(a, c) == c || LCA(b, c) == c))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}