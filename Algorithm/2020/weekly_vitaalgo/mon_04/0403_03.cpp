// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// p[i]를 이용한다.
	// N을 (0..len-1)부터 (len-2..len-1)까지 돌린다.
	string H; // haystack
	cin >> H;
	int n = H.size();
	int ans = 1;
	for (int i = 0; i < n - 1; i++) {
		int p[3001] = { 0, };
		string N = H.substr(i);
		int m = N.size();
		int begin = 1, matched = 0;
		while (begin + matched < m) {
			if (N[begin + matched] == N[matched]) {
				matched++;
				p[begin + matched - 1] = matched;
				ans = max(ans, matched);
			}
			else {
				if (!matched)
					begin++;
				else {
					begin += matched - p[matched - 1];
					matched = p[matched - 1];
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}