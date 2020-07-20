// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii input[1001];
// 뽑아낸 선분들.
vector<pair<int, int>> line;
int ccw(pii a, pii b, pii c) {
	int res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}
int inter(pair<pii, pii> a, pair<pii, pii> b) {
	int ab = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
	int cd = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
	if (ab == 0 && cd == 0) {
		pii a_fi = a.first;
		pii a_se = a.second;
		pii b_fi = b.first;
		pii b_se = b.second;
		if (a_fi > a_se) swap(a_fi, b_se);
		if (b_fi > b_se) swap(b_fi, b_se);
		return b_fi <= a_se && a_fi <= b_se;
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 가장 다른 선분과 적게 교차되는 선분부터 추가함
	int n;
	cin >> n;
	line.reserve(n / 2);
	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;
	// 일단 점들을 x 오름차순, y 오름차순으로 정렬
	sort(input, input + n);
	// 앞에서부터 이어보자.
	bool used[1001] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (!used[j]) {
				bool check = true;
				for (pair<int, int> l : line)
					if (inter({ input[l.first], input[l.second] }, { input[i], input[j] })) {
						check = false;
						break;
					}
				if (check) {
					used[j] = true;
					used[i] = true;
					line.push_back({ i, j });
				}
			}
	}
	cout << line.size() << '\n';
	for (auto l : line)
		cout << l.first + 1 << " " << l.second + 1 << '\n';
	return 0;
}