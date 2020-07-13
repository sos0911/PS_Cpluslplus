// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
#define SIZE 50
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
int input[SIZE];
// ù��°, �ι�° ������ �κ����յ�
vvi divset(2, vi()); // ������ ����.
vvi parset(2, vi()); // �κ����� ����

ll count(vi& parset, int val) {
	return upper_bound(parset.begin(), parset.end(), val) - lower_bound(parset.begin(), parset.end(), val);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// to pointer
	// �� �������� �ɰ�, �� ������ �κ������� ���Ѵ�.
	// 2*20*2 = 2�鸸
	// �� ���տ��� ���� ���� ���� �����ϴ�.
	// lowerbound
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	// input�� 0�� �ƴϴ�.
	divset[0].reserve(n / 2);
	divset[1].reserve(n - n / 2);
	parset[0].reserve(pow(2, n / 2));
	parset[1].reserve(pow(2, n - n / 2));

	for (int i = 0; i < n / 2; i++) {
		int input;
		cin >> input;
		divset[0].push_back(input);
	}
	for (int i = 0; i < n - n / 2; i++) {
		int input;
		cin >> input;
		divset[1].push_back(input);
	}
	// �κ������� ���Ѵ�.
	for (int i = 0; i < 2; i++) {
		int setlen = divset[i].size();
		for (int j = (1 << setlen); j > 0; j--) {
			int sum = 0;
			for (int k = 0; k < setlen; k++) {
				if (j & (1 << k)) sum += divset[i][k];
			}
			// �κ����� �߰�
			// �������� �ڵ����� �߰���
			parset[i].push_back(sum);
		}
		sort(parset[i].begin(), parset[i].end());
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < parset[i].size(); j++)
			cout << parset[i][j] << " ";
		cout << '\n';
	}
	// two pointer
	auto l = parset[0].begin(), r = parset[1].end() - 1;
	ll ans = 0;
	while (l != parset[0].end() && r >= parset[1].begin()) {
		if (*l + *r == 0) {
			ans += count(parset[0], *l) + count(parset[0], *r);
			l = upper_bound(parset[0].begin(), parset[0].end(), *l);
			r = lower_bound(parset[1].begin(), parset[1].end(), *r) - 1;
		}
		else if (*l + *r > 0)
			r--;
		else
			l++;
	}
	cout << ans - 1 << '\n'; // �����ճ��� ��Ī�� ��� ����
	return 0;
}