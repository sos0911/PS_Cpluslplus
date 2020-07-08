// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
int n;
pii dir[4] = { {0,-1}, {0,1}, {1,0}, {-1,0} };
int inputmap[1021][1021];
int visitarr[1021][1021];
vector<vector<pii>> warp(10, vector<pii>());
// 범위 내, 벽이 아닌지 체크
bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n && inputmap[y][x] != 1;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	fill_n(&visitarr[0][0], 1021 * 1021, INF);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> inputmap[i][j];
			// 워프 좌표 저장
			if (inputmap[i][j] > 1)
				warp[inputmap[i][j]].push_back({ i,j });
		}
	// (0,0)부터 시작
	// (y,x)
	// bfs
	// (현재 좌표, 누적된 시간)
	pii inipos = { 0,0 }, tarpos = { n - 1,n - 1 };
	queue<pair<pii, int>> bfsq;
	bfsq.push({ inipos, 1 });
	while (!bfsq.empty()) {
		auto curstate = bfsq.front();
		bfsq.pop();
		if (curstate.first == tarpos) {
			cout << curstate.second << '\n';	
			return 0;
		}
		int cury = curstate.first.first;
		int curx = curstate.first.second;
		// 워프 가능한 경우 처리
		if (inputmap[cury][curx] > 1) {
			for (int i = 0; i < warp[inputmap[cury][curx]].size(); i++) {
				int nexty = warp[inputmap[cury][curx]][i].first;
				int nextx = warp[inputmap[cury][curx]][i].second;
				if (curstate.second + 1 < visitarr[nexty][nextx]) {
					visitarr[nexty][nextx] = curstate.second + 1;
					bfsq.push({ { nexty,nextx }, curstate.second + 1 });
				}
			}
		}
		// 주위 네방향으로 뻗음
		for (int i = 0; i < 4; i++) {
			int nexty = curstate.first.first + dir[i].first;
			int nextx = curstate.first.second + dir[i].second;
			if (check(nexty, nextx) && curstate.second + 1 < visitarr[nexty][nextx]) {
				visitarr[nexty][nextx] = curstate.second + 1;
				bfsq.push({ { nexty,nextx }, curstate.second + 1 });
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}