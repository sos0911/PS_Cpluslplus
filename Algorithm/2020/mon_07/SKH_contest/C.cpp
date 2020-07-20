// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
struct com {
	char u;
	int p;
};
com comlist[100001];
// 0 : 한양, 1 : 고려, 2 : 숭실
// dp[i][j][k] : i idx 포함 그 뒤 대회에서 j번 움직일수있고 현재위치가 k일때 최대 상금
ll dp[100001][101][3];
ll solve(int idx, int left, int univ) {
	// dp??
	// 취할수있는 건 두가지
	// 남아있느냐 아니면 이동하느냐
	// 지금 idx index의 대회를 결정해야한다.
	if (idx == n)
		return 0;
	ll& ref = dp[idx][left][univ];
	if (ref != -1)
		return ref;
	// 더이상 이동불가
	if (!left) {
		ll sum = 0;
		for (int i = idx; i < n; i++) {
			int thisuniv = comlist[i].u == 'H' ? 0 : comlist[i].u == 'K' ? 1 : 2;
			if (univ == thisuniv)
				sum += comlist[i].p;
		}
		return dp[idx][left][univ] = sum;
	}

	int curuniv = comlist[idx].u == 'H' ? 0 : comlist[idx].u == 'K' ? 1 : 2;

	if (curuniv == univ)
		ref = max(ref, comlist[idx].p + solve(idx + 1, left, univ));
	else {
		ref = max(ref, comlist[idx].p + solve(idx + 1, left - 1, curuniv));
		ref = max(ref, solve(idx + 1, left, univ));
	}
	return ref;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 완탐
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		char u;
		int p;
		cin >> u >> p;
		comlist[i] = { u, p };
	}
	cout << solve(0, m, 0) << '\n';
	return 0;
}