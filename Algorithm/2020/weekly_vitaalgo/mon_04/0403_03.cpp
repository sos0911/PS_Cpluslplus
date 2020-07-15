// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// p[i]�� �̿��Ѵ�.
	// N�� (0..len-1)���� (len-2..len-1)���� ������.
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