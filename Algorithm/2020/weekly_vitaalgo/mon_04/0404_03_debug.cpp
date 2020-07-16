// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
pair<string, string> generate_random_str() {
	// 입력을 랜덤으로 만든다.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 10);

	uniform_int_distribution<int> dis2(0, 26);

	int a_size = dis(gen), b_size = dis(gen);
	string a, b;
	a.assign(a_size, '0');
	b.assign(b_size, '0');
	for (int i = 0; i < a_size; i++)
		a[i] = (char)(dis2(gen) + 'a');
	for (int j = 0; j < b_size; j++)
		b[j] = (char)(dis2(gen) + 'a');
	return { a,b };
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		string a, b;
		auto ret = generate_random_str();
		a = ret.first, b = ret.second;
		int n = a.size(), m = b.size();


		// lcs
		int lcs[1001][1001] = { 0, };
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i - 1] == b[j - 1])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else
					lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		int ans1 = max(n, m) - lcs[n][m];

		// lcs2
		int d[1010][1010] = { 0, };
		for (int i = 0; i <= n; ++i)
			d[i][0] = i;
		for (int i = 0; i <= m; ++i)
			d[0][i] = i;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i] == b[j])
					d[i + 1][j + 1] = d[i][j];
				else
					d[i + 1][j + 1] = min({ d[i][j + 1], d[i + 1][j], d[i][j] }) + 1;
			}
		}
		int ans2 = d[n][m];

		if (ans1 != ans2) {
			cout << "detected : " << ans1 << " " << ans2 << '\n';
			cout << "a : " << a << '\n';
			cout << "b : " << b << '\n';
			break;
		}
	}
	return 0;
}