// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
int dp[501][501];
struct info {
	int l, r;
};
info pipe[501];

int solve(int lidx, int ridx) {
	// 가장왼쪽 파이프 idx가 lidx, rdix가 그 반대일시
	// 완성하는 가장 적은 cost 반환
	if (lidx == ridx)
		return 0;
	int& ret = dp[lidx][ridx];
	if (ret != -1)
		return ret;

	ret = INF;
	// 중간 지점을 모두 시도해본다.
	for (int i = lidx + 1; i <= ridx; i++) {
		int a = solve(lidx, i - 1) + solve(i, ridx) + pipe[lidx].l * pipe[i].l * pipe[ridx].r;
		ret = min(ret, a);
	}

	return ret;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pipe[i].l >> pipe[i].r;
	cout << solve(0, n - 1) << '\n';
	return 0;
}