// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
// 좌표 시작은 (0,0)
// (y,x)
// (0,0) -> (n-1,n-1)
int inputmap[1001][1001];
int visitarr[1001][1001];
int n;
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
const int INF = 1e9;
bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
struct info {
	pii coord;
	int val;
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> inputmap[i][j];
	// visitarr 초기화
	for (int i = 0; i < n; i++)
		fill(visitarr[i], visitarr[i] + n, INF);
	deque<info> bfsq;
	bfsq.push_front({ { 0,0 }, 0 });
	visitarr[0][0] = 0;
	while (!bfsq.empty()) {
		info curpos = bfsq.front();
		bfsq.pop_front();
		if (curpos.coord == make_pair(n - 1, n - 1)) {
			cout << curpos.val << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nexty = curpos.coord.first+ dir[i][0];
			int nextx = curpos.coord.second + dir[i][1];
			if (check(nexty, nextx)) {
				if (inputmap[nexty][nextx] && curpos.val < visitarr[nexty][nextx]) {
					visitarr[nexty][nextx] = curpos.val;
					bfsq.push_front({ {nexty,nextx}, curpos.val });
				}
				if (!inputmap[nexty][nextx] && curpos.val + 1 < visitarr[nexty][nextx]) {
					visitarr[nexty][nextx] = curpos.val+1;
					bfsq.push_back({ {nexty,nextx}, curpos.val+1 });
				}
			}
		}
	}
	return 0;
}