// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
bool comp(pii a, pii b) {
	return a.second < b.second;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pii> input(n, { -1,-1 });
	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;
	// 두번째 인자로 정렬
	sort(input.begin(), input.end(), comp);
	int num = 1;
	bool possi = true;
	for (int i = 1; i < n; i++) {
		if (input[i - 1].se == input[i].se) {
			if (++num > 2) {
				possi = false;
				break;
			}
		}
		else
			num = 1;
	}
	cout << possi << '\n';
	return 0;
}