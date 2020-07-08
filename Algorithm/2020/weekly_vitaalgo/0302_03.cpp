// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
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
// ���� ��, ���� �ƴ��� üũ
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
			// ���� ��ǥ ����
			if (inputmap[i][j] > 1)
				warp[inputmap[i][j]].push_back({ i,j });
		}
	// (0,0)���� ����
	// (y,x)
	// bfs
	// (���� ��ǥ, ������ �ð�)
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
		// ���� ������ ��� ó��
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
		// ���� �׹������� ����
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