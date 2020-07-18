// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
int c1[51] = { 0, }, c2[51] = { 0, };
int inputarr[102];
int solve(int idx, int c1idx, int c2idx) {
	//cout << "solve called : " <<idx<<" "<<c1idx<<" "<<c2idx<<" "<<'\n';
	//for (int i = 0; i < n; i++) {
	//	cout << c1[i] << " ";
	//}
//		cout << '\n';
	//
	//for (int i = 0; i < n; i++) {
	//	cout << c2[i] << " ";
	//}
	//cout << '\n';

	// idx를 어느 곳에 넣을지 결정해야함
	if (c1idx == n && c2idx == n) {
		bool check = true;
		for (int i = 0; i < n; i++)
			if (c1[i] != c2[i]) {
				check = false;
				break;
			}
		if (check) {
			for (int i = 0; i < n; i++)
				cout << c1[i] << " ";
			cout << '\n';
			return 1;
		}
		return 0;
	}

	// 검사
	if (c1idx >= 1 && c2idx >= 1) {
		int minidx = min(c1idx, c2idx);
		if (c1[minidx - 1] != c2[minidx - 1]) {
			/*
			cout << "mismatched " << minidx <<'\n';
			for (int i = 0; i < n; i++) {
				cout << c1[i] << " ";
			}
			cout << '\n';

			for (int i = 0; i < n; i++) {
				cout << c2[i] << " ";
			}
			cout << '\n';
			*/
			return 0;
		}
	}

	if (c1idx != n) {
		c1[c1idx] = inputarr[idx];
		if (solve(idx + 1, c1idx + 1, c2idx))
			return 1;
		c1[c1idx] = 0;
	}
	if (c2idx != n) {
		c2[c2idx] = inputarr[idx];
		if (solve(idx + 1, c1idx, c2idx + 1))
			return 1;
		c1[c1idx] = 0;
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 완전탐색
	int noft;
	cin >> noft;
	for (int i = 0; i < noft; i++) {
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
			cin >> inputarr[i];
		solve(0, 0, 0);
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
	}
	return 0;
}