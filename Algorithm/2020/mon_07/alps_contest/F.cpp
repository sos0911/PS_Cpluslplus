// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int b_n[6], b_c[6]; // 수용 개수, 설치비용
int noft[6];
const int INF = 1e9;
int mincost=INF;
int n, k;
// 해당 cost로 해결하는 가짓수.
int nofcost[51] = { 0, };

void solve(int left, int cost, int lastidx, int nofb) {
	// 물건 남은갯수 : left, 마지막 사용 블록 idx : lastidx
	// 사용 블록 수 : nofb
	if (left <= 0 && nofb <= n) {
		mincost = min(mincost, cost);
		nofcost[cost]++;
		return;
	}
	if (nofb >= n)
		return;
	for (int i = lastidx; i < k; i++)
		solve(left - b_n[i], cost + b_c[i], i, nofb + 1);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 브루트포스로 그냥 찾아본다..
	// 쿼리가 들어올 때마다.
	// 쿼리당 찾아볼 조합은 많아봐야 5^5..
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> noft[i];
	for (int i = 0; i < k; i++)
		cin >> b_n[i] >> b_c[i];
	for (int i = 0; i < n; i++) {
		solve(noft[i], 0, 0, 0);
		cout << mincost<<" "<< nofcost[mincost] << '\n';
		mincost = INF;
		memset(nofcost, 0, sizeof(nofcost));
	}
	return 0;
}