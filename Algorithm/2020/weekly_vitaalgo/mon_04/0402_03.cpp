// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpi;
typedef vector<pii> vpi;
int n, m;
vvpi adj;
bool visitarr[10001] = { false, };
struct comp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 프림 알고리즘
	// 최소 스패닝 트리
	cin >> n >> m;
	// (노드 idx, 가중치) 저장
	adj.assign(n + 1, vpi());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	// 최소 스패닝 트리 만들기
	// (상대노드 idx, 가중치)
	// queue 안에는 스패닝 트리 노드 -> 스패닝 트리가 아닌 노드 사이 edge 저장
	int ans = 0;
	priority_queue<pii, vector<pii>, comp> priq;
	priq.push({ 1,0 });
	while (!priq.empty()) {
		pii curnode = priq.top();
		priq.pop();
		// 이미 상대노드가 스패닝트리에 속해 있을 수도 있다.
		// 이미 앞에서 가중치가 더 적은 경로를 찾아냈을 경우.
		if (visitarr[curnode.first])
			continue;
		visitarr[curnode.first] = true;
		ans += curnode.second;
		for(int i=0;i<adj[curnode.first].size();i++)
			if (!visitarr[adj[curnode.first][i].first]) {
				priq.push(adj[curnode.first][i]);
			}
	}
	cout << ans << '\n';
	return 0;
}