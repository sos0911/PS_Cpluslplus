// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int inputmap[1001][1001];
bool visitarr[1001][1001] = { false };
int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
int n;
bool check(int y, int x) {
	// 범위 내 가습제 && 주위에 0이 하나라도 있는지 체크
	bool check = false;
	if (y >= 0 && y < n && x >= 0 && x < n && inputmap[y][x]) {

		for (int d = 0; d < 4; d++) {
			int nexty = y + dir[d][0];
			int nextx = x + dir[d][1];
			if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n && !inputmap[nexty][nextx]) {
				check = true;
				break;
			}
		}
	}
	return check;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	// 꽉 차있는 경우면 항상 -1
	bool Isend = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> inputmap[i][j];
			if (!inputmap[i][j])
				Isend = false;
		}
	if (Isend) {
		cout << -1 << '\n';
		return 0;
	}
	// 매 순간마다 사라질 놈들을 list로 관리한다.
	queue<pii> bfsq;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (check(i, j)) {
				visitarr[i][j] = true;
				bfsq.push({ i,j });
			}
	// 경과한 시간
	int t_val = 0;
	// bfs
	while (!bfsq.empty()) {
		int len = bfsq.size();
		for (int i = 0; i < len; i++) {
			pii curpos = bfsq.front();
			bfsq.pop();
			for (int d = 0; d < 4; d++) {
				int nexty = curpos.first + dir[d][0];
				int nextx = curpos.second + dir[d][1];
				// 현재 좌표와 맞닿은 제습제는 무조건 다음 타임에 제거된다.
				if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n && !visitarr[nexty][nextx] && inputmap[nexty][nextx]) {
					visitarr[nexty][nextx] = true;
					bfsq.push({ nexty,nextx });
				}
			}
		}
		t_val++;
	}
	cout << t_val << '\n';
	return 0;
}