// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int n;
const int INF = 1e9;
bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// �ΰ��� �����
	// �� �����ڿ��� ���ε������� �Ÿ�, �������忡�� ���� ��ġ������ �Ÿ�
	
	// �� �������� �ּ��ð�
	int val[10] = { 0, };
	pii pos[10]; // ���� ��ġ
	cin >> n;
	int cmap[1001][1001];

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> cmap[i][j];
			if (cmap[i][j] >= 3 && cmap[i][j] < 10)
				pos[cmap[i][j]] = { i,j };
		}
	// �� �����ڿ� ���� bfs.
	// ���ε��������� �Ÿ�
	for (int i = 5; i < 10; i++) {
		queue<pii> bfsq;
		bool visitarr[1001][1001] = { false, };
		bfsq.push(pos[i]);
		visitarr[pos[i].first][pos[i].second] = true;
		int curtime = 0;
		while (!bfsq.empty()) {
			int len = bfsq.size();
			for (int j = 0; j < len; j++) {
				pii curpos = bfsq.front();
				bfsq.pop();
				if (curpos == pos[4]) {
					val[i] += curtime;
					goto esc;
				}
				for (int d = 0; d < 4; d++) {
					int nexty = curpos.first + dir[d][0];
					int nextx = curpos.second + dir[d][1];
					if (check(nexty, nextx) && cmap[nexty][nextx] && !visitarr[nexty][nextx]) {
						visitarr[nexty][nextx] = true;
						bfsq.push({ nexty,nextx });
					}
				}
			}
			curtime++;
		}
	esc:
		continue;
	}
	// �������� -> �� ������ ������ġ bfs
	for (int i = 5; i < 10; i++) {
		queue<pii> bfsq;
		bool visitarr[1001][1001] = { false, };
		bfsq.push(pos[3]);
		visitarr[pos[3].first][pos[3].second] = true;
		int curtime = 0;
		while (!bfsq.empty()) {
			int len = bfsq.size();
			for (int j = 0; j < len; j++) {
				pii curpos = bfsq.front();
				bfsq.pop();
				if (curpos == pos[i]) {
					val[i] += curtime;
					goto esc2;
				}
				for (int d = 0; d < 4; d++) {
					int nexty = curpos.first + dir[d][0];
					int nextx = curpos.second + dir[d][1];
					if (check(nexty, nextx) && cmap[nexty][nextx] && !visitarr[nexty][nextx]) {
						visitarr[nexty][nextx] = true;
						bfsq.push({ nexty,nextx });
					}
				}
			}
			curtime++;
		}
	esc2:
		continue;
	}
	int suspectidx = -1, minval = INF;
	for (int i = 5; i < 10; i++) {
		if (val[i] < minval) {
			minval = val[i];
			suspectidx = i;
		}
	}
	cout << suspectidx << '\n';
	return 0;
}