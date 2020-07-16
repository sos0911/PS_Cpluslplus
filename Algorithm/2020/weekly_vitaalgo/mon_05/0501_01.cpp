// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1e9 + 7;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int n;
ll dp[501][501];
int curmap[501][501];

bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

ll solve(int y, int x) {
	// (y,x)에서 (n-1,n-1)로 가는 경로 가짓수 반환
	if (y == n - 1 && x == n - 1)
		return 1;

	ll& ret = dp[y][x];
	if (ret != -1)
		return ret;
	
	for (int d = 0; d < 4; d++) {
		int nexty = y + dir[d][0];
		int nextx = x + dir[d][1];
		if (check(nexty, nextx) && curmap[nexty][nextx] < curmap[y][x]) {
			ret += solve(nexty, nextx);
			ret %= mod;
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> curmap[i][j];
	// (1,1)의 높이부터 아래로 진행한다.
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	return 0;
}