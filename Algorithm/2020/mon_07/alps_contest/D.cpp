// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
int ans = -1;
pii info[101]; // (���� ����, �ູ��) ����
bool check[101] = { false, }; // �̹� ���ָ� ��°�?
int n, m;
int solve(int left, int rep, int curidx, int sum) {
	// ������ �������� 
	// ��� �ູ�� ��ȯ

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
	// �賶����
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> info[i].first >> info[i].second;
	sort(info + 1, info + n + 1, comp);

	// ���ָ� 0��, 1��, 2��, 3�� �����ϰ� �������� ���� �Ǵ� �� 4ĵ����
	// ���� idx�� 1����

	// 0��
	ans = max(ans, solve(m, min(m/10000, n/4), 1, 0));

	// 1��
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		int left = m - info[i].first;
		if(left >= 0)
			ans = max(ans, solve(left, min(left / 10000, (n - 1) / 4), 1, info[i].second));
		check[i] = false;
	}

	// 2��
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

	// 3��
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