// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int n, k;
struct info {
	// left : ���� ���� ��������
	int y, x, left;
};
bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ������ �� ���ذ� �Ȱ�����..
	// ��·�� ���� ��� ���� k�������� �־ ����̶� �����Ѵ�.
	cin >> n >> k;
	// (y,x)
	bool visitarr[1001][1001] = { false, };
	int curmap[1001][1001];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> curmap[i][j];

	int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
	queue<info> bfsq;
	bfsq.push({ 0,0,k });
	visitarr[0][0] = true;
	int curtime = 1;
	while (!bfsq.empty()) {
		int len = bfsq.size();
		for (int i = 0; i < len; i++) {
			info curinfo = bfsq.front();
			bfsq.pop();
			if (curinfo.y == n - 1 && curinfo.x == n - 1) {
				cout << curtime << '\n';
				return 0;
			}
			for (int d = 0; d < 4; d++) {
				int nexty = curinfo.y + dir[d][0];
				int nextx = curinfo.x + dir[d][1];
				if (check(nexty, nextx) && !visitarr[nexty][nextx]) {
					visitarr[nexty][nextx] = true;
					if (curmap[nexty][nextx]) {
						if (curinfo.left)
							bfsq.push({ nexty,nextx,curinfo.left - 1 });
					}
					else
						bfsq.push({ nexty,nextx,curinfo.left });
				}
			}
		}
		curtime++;
	}
	cout << -1 << '\n';
	return 0;
}