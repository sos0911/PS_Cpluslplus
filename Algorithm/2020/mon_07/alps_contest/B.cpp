// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int inputmap[51][51];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int low = 200, high = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> inputmap[i][j];
			low = min(low, inputmap[i][j]);
			high = max(high, inputmap[i][j]);
		}
	// (0,0)부터
	// 최소 ~ 최대의 값 범위에서 시작해봄.
	int minerror = 2e9;
	int mincache[51][51];
	for (int i = low; i <= high; i++)
		for (int j = i; j < high + 1; j++) {
			int curerror = 0;
			int cache[51][51] = { 0, };
			for(int h=0;h<n;h++)
				for (int w = 0; w < m; w++) {
					if ((i - inputmap[h][w]) * (i - inputmap[h][w]) <= (j - inputmap[h][w]) * (j - inputmap[h][w])) {
						curerror += (i - inputmap[h][w]) * (i - inputmap[h][w]);
						cache[h][w] = i;
					}
					else {
						curerror += (j - inputmap[h][w]) * (j - inputmap[h][w]);
						cache[h][w] = j;
					}
				}
			if (curerror < minerror) {
				minerror = curerror;
				for (int h = 0; h < n; h++)
					for (int w = 0; w < m; w++)
						mincache[h][w] = cache[h][w];
			}
		}
	cout << minerror << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mincache[i][j] << " ";
		cout << '\n';
	}
	return 0;
}