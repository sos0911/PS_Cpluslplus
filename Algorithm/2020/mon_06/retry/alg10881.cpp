// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int a[6], b[6];

int solve() {
	int minarea = INF;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++) {
				if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3)
					continue;

				minarea = min(minarea, (a[i] + a[j] + a[k]) * max({ b[i], b[j], b[k] }));
				minarea = min(minarea, min(a[i]+a[j], a[k]) * (max(b[i], b[j]) + b[k]));
			}
	return minarea;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noftc;
	cin >> noftc;
	for (int i = 0; i < noftc; i++) {
		for (int j = 0; j < 3; j++) {
			int in1, in2;
			cin >> in1 >> in2;
			a[j] = b[j + 3] = in1;
			b[j] = a[j + 3] = in2;
		}
		cout << solve() << '\n';
	}
	return 0;
}