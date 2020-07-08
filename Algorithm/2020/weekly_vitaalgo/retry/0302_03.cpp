// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9, arrsize = 1021;
int n;
pii dir[4] = { {0,-1}, {0,1}, {1,0}, {-1,0} };
vector<vector<int>> inputmap(arrsize, vector<int>(1021, -1));
vector<vector<int>> visitarr(arrsize, vector<int>(1021, INF));
vector<vector<pii>> warp(10, vector<pii>());
struct Info {
	// warpcheck�� bitmask
	// �ѹ� �� ���� ���ڴ� �ٽ� ���x
	int y, x, val, warpcheck;
};
// ���� ��, ���� �ƴ��� üũ
bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n && inputmap[y][x] != 1;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	// fill_n(&visitarr[0][0], 1021 * 1021, INF);
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
	queue<Info> bfsq;
	// struct�� {}���� initializer ����
	bfsq.push({ inipos.fi, inipos.se, 1, 0 });
	// while(true)�� runtime error
	while (!bfsq.empty()) {
		auto curstate = bfsq.front();
		bfsq.pop();
		if (curstate.y == tarpos.fi && curstate.x == tarpos.se) {
			cout << curstate.val << '\n';
			return 0;
		}
		int cury = curstate.y;
		int curx = curstate.x;
		// ���� ������ ��� ó��
		if (inputmap[cury][curx] > 1 && !(curstate.warpcheck & (1 << inputmap[cury][curx]))) {
			for (int i = 0; i < warp[inputmap[cury][curx]].size(); i++) {
				int nexty = warp[inputmap[cury][curx]][i].first;
				int nextx = warp[inputmap[cury][curx]][i].second;
				if (curstate.val + 1 < visitarr[nexty][nextx]) {
					visitarr[nexty][nextx] = curstate.val + 1;
					bfsq.push({ nexty, nextx , curstate.val + 1 , curstate.warpcheck | (1 << inputmap[cury][curx]) });
				}
			}
		}
		// ���� �׹������� ����
		for (int i = 0; i < 4; i++) {
			int nexty = curstate.y + dir[i].first;
			int nextx = curstate.x + dir[i].second;
			if (check(nexty, nextx) && curstate.val + 1 < visitarr[nexty][nextx]) {
				visitarr[nexty][nextx] = curstate.val + 1;
				bfsq.push({ nexty, nextx , curstate.val + 1 , curstate.warpcheck });
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}