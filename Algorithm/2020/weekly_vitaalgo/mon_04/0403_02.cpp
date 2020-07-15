// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// kmp 구현
	string H, N; // 짚더미, 바늘
	cin >> H >> N;
	// 먼저 p[i] 계산
	// p[i] : 0..i까지 N을 볼때 접두사,접미사가 동시에 되는 부분문자열 최대길이
	// N[0..i]에서 자기 자신을 빼고 생각한다.
	// 만약 같이 넣고 생각하면 N[len-1] = len이 되버림.
	int p[1000001] = { 0, };
	int begin = 1, matched = 0;
	int n = H.size(), m = N.size();
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			// 잘해봐야 p[1+1-1 = 1]부터 시작
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
	// p[i]를 바탕으로 kmp
	// needle.len == 1일때에도 동작.
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