// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define INF 1e9
#define SIZE 16
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
vvi adj;
int n;
// 시작점이 뭐였는지는 중요하지 않다.
// 시작점은 항상 idx 0으로 생각한다.
// dp[i][j] : bitmask i 방문했을 때 (j) 제외, 현재 j를 방문했을때 이 상태에서 정답으로 가는 cost.
int dp[1 << (SIZE)][SIZE];
int solve(int idx, int visit) {
	cout << "idx : " << idx << " visit : " << bitset<17>(visit) << '\n';
	// edge cost=0이면 갈수없다
	// visit을 bitmask로 해야한다.
	// 16이니 2^16.. int형으로 충분
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
	// dfs로 조사
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