// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100001];
struct node {
	// 만들어질 시 d,p는 0으로 자동 초기화
	int d, p;
};
node info[100001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// lca
	// dp 사용x 버전.
	// 단순히 트리 만든다음 입력받아서 위로 올린다.
	// 각 노드마다 깊이와 부모 노드는 유지해야 한다.
	// adj 만들고 bfs or dfs로 위 정보 수집
	cin >> n;
	for (int i = 0; i < n-1; i++) {
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
	// 깊이를 같은 것으로 맞춰줌
	if (info[a].d < info[b].d)
		swap(a, b);
	if (info[a].d != info[b].d)
		while (info[a].d != info[b].d)
			a = info[a].p;


	// 이제 동시에 1씩 위로 올라감
	while (a != b) {
		a = info[a].p;
		b = info[b].p;
	}
	cout << a << '\n';
	return 0;
}