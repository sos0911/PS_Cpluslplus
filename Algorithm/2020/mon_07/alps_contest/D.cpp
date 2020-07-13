// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
int ans = -1;
pii info[101]; // (맥주 가격, 행복도) 저장
bool check[101] = { false, }; // 이미 맥주를 샀는가?
int n, m;
int solve(int left, int rep, int curidx, int sum) {
	// 생성된 조합으로 
	// 얻는 행복도 반환

	int limit = rep * 4;
	int nofb = 0;
	while (nofb < limit) {
		if (!check[curidx]) {
			sum += info[curidx].second;
			nofb++;
		}
		curidx++;
	}

	return sum;
}
bool comp(pii a, pii b) {
	return a.second > b.second;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 배낭문제
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> info[i].first >> info[i].second;
	sort(info + 1, info + n + 1, comp);

	// 맥주를 0개, 1개, 2개, 3개 선택하고 나머지는 돈이 되는 한 4캔만원
	// 맥주 idx는 1부터

	// 0개
	ans = max(ans, solve(m, min(m/10000, n/4), 1, 0));

	// 1개
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		int left = m - info[i].first;
		if(left >= 0)
			ans = max(ans, solve(left, min(left / 10000, (n - 1) / 4), 1, info[i].second));
		check[i] = false;
	}

	// 2개
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		for (int j = i + 1; j <= n; j++) {
			check[j] = true;
			int left = m - info[i].first - info[j].first;
			if (left >= 0)
				ans = max(ans, solve(left, min(left / 10000, (n - 2) / 4), 1, info[i].second + info[j].second));
			check[j] = false;
		}
		check[i] = false;
	}

	// 3개
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		for (int j = i + 1; j <= n; j++) {
			check[j] = true;
			for (int k = j + 1; k <= n; k++) {
				check[k] = true;
				int left = m - info[i].first - info[j].first - info[k].first;
				if (left >= 0)
					ans = max(ans, solve(left, min(left / 10000, (n - 3) / 4), 1, info[i].second + info[j].second + info[k].second));
				check[k] = false;
			}
			check[j] = false;
		}
		check[i] = false;
	}

	cout << ans << '\n';

	return 0;
}