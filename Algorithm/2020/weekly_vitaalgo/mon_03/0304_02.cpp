// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> pop; // �α��� ����
// INF�� ����x, -1�̸� ä���Ұ���
int dp[10001][101];
const int INF = 1e9;
bool desc(int a, int b) {
	return a > b;
}
int solve(int left, int idx) {
	// ���� �� left, ���� ��ġ idx�϶�
	// idx ���� �� ���ķ� ����ؼ� ��� ���� ���� ���� �� ��ȯ
	// �� �ȸ����� -1
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
		// ������ ã�Ƴ´� �ϴ���, �ڿ��� �� ���� ������ ���� �� �ִ�.
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
	// �ߺ�����
	pop.erase(unique(pop.begin(), pop.end()), pop.end());
	// ������������ ����
	sort(pop.begin(), pop.end(), desc);
	for (int i = 0; i < 10001; i++)
		fill(dp[i], dp[i] + 101, INF);
	cout << solve(k, 0) << '\n';
	return 0;
}