// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// kmp ����
	string H, N; // ¤����, �ٴ�
	cin >> H >> N;
	// ���� p[i] ���
	// p[i] : 0..i���� N�� ���� ���λ�,���̻簡 ���ÿ� �Ǵ� �κй��ڿ� �ִ����
	// N[0..i]���� �ڱ� �ڽ��� ���� �����Ѵ�.
	// ���� ���� �ְ� �����ϸ� N[len-1] = len�� �ǹ���.
	int p[1000001] = { 0, };
	int begin = 1, matched = 0;
	int n = H.size(), m = N.size();
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			// ���غ��� p[1+1-1 = 1]���� ����
			p[begin + matched - 1] = matched;
		}
		else {
			if (!matched)
				++begin;
			else {
				begin += matched - p[matched - 1];
				matched = p[matched - 1];
			}
		}
	}
	// p[i]�� �������� kmp
	// needle.len == 1�϶����� ����.
	begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			matched++;
			if (matched == m) cout << begin + matched << '\n';
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
	return 0;
}