// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> pop; // 인구수 저장
// INF면 세팅x, -1이면 채우기불가능
int dp[10001][101];
const int INF = 1e9;
bool desc(int a, int b) {
	return a > b;
}
int solve(int left, int idx) {
	// 남은 수 left, 현재 위치 idx일때
	// idx 포함 그 이후로 사용해서 얻는 가장 좋은 유닛 수 반환
	// 딱 안맞으면 -1
	if (!left)
		return 0;
	if (left && idx == pop.size())
		return -1;

	int& ret = dp[left][idx];
	if (ret != INF)
		return ret;

	bool check = false;

	for (int i = left / pop[idx]; i >= 0; i--) {
		int res;
		// 조합을 찾아냈다 하더라도, 뒤에서 더 좋은 조합이 나올 수 있다.
		if ((res = solve(left - i * pop[idx], idx + 1)) != -1) {
			check = true;
			ret = min(ret, res + i);
		}
	}
	return check? ret : ret = -1;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	pop.reserve(n);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input <= k)
			pop.push_back(input);
	}
	// 중복제거
	pop.erase(unique(pop.begin(), pop.end()), pop.end());
	// 내림차순으로 정렬
	sort(pop.begin(), pop.end(), desc);
	for (int i = 0; i < 10001; i++)
		fill(dp[i], dp[i] + 101, INF);
	cout << solve(k, 0) << '\n';
	return 0;
}