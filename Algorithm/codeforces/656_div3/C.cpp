// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int maxsize = 2e5;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin >> noft;
	int inputarr[maxsize+1];
	for (int i = 0; i < noft; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> inputarr[i];
		// 뒤에서부터 오름차순인지 확인
		int curidx = n - 2, pointidx = n - 1;
		while (curidx >= 0 && inputarr[curidx] >= inputarr[curidx + 1])
			curidx--;
		if (curidx < 0) {
			cout << 0 << '\n';
			continue;
		}
		// 그 점부터 앞이 내림차순인지 확인
		while (curidx >= 0 && inputarr[curidx] <= inputarr[curidx + 1])
			curidx--;
		if (curidx < 0) {
			cout << 0 << '\n';
		}
		else
			cout << curidx + 1 << '\n';
	}
	return 0;
}