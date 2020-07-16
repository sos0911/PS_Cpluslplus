// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// lcs와 비슷함
	// cost[i][j] : a의 i번째 문자, b의 j번째 문자까지 볼때 서로 맞추는 최소 cost
	int cost[1001][1001] = { 0, };
	// 초기화
	for (int i = 1; i <= m; i++)
		cost[0][i] = i;
	for (int i = 1; i <= n; i++)
		cost[i][0] = i;
	// 수행
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1])
				cost[i][j] = cost[i - 1][j - 1];
			else
				cost[i][j] = min({ cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1] }) + 1;
	cout << cost[n][m] << '\n';
	return 0;
}