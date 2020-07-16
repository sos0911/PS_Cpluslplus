// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 문제를 정확히는 이해 못하겠다..
	// n^2로 일단 완전탐색
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// lcs[i][j] : a의 1~i번째 글자, b의 1~j번째 글자를 봤을때 lcs 길이
	// lcs에 쓰이는 idx와 실제 string idx는 차이가 있다. 주의!
	int lcs[1001][1001] = { 0, };
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
	cout << lcs[n][m] << '\n';
	return 0;
}