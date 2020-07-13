// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vl;
ll n, m;
ll crimat[111][111] = { 0, };
ll ansmat[111][111] = { 0, };
const int matsize = 111;

void matmul(bool check) {
	// ����� ���Ѵ�.
	// true : ans�� cri�� ����
	// false : cri �ι� ��Ƣ��
	ll res[matsize][matsize];
	if (check) {
		for(int i=0;i<m;i++)
			for (int j = 0; j < m; j++) {
				res[i][j] = 0;
				for (int k = 0; k < m; k++) {
					res[i][j] += crimat[i][k] * ansmat[k][j];
					res[i][j] %= mod;
				}
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				ansmat[i][j] = res[i][j];
	}
	else {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++) {
				res[i][j] = 0;
				for (int k = 0; k < m; k++) {
					res[i][j] += crimat[i][k] * crimat[k][j];
					res[i][j] %= mod;
				}
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				crimat[i][j] = res[i][j];
	}
}

void matpow(ll rep) {
	// rep��ŭ crimat�� ���Ѵ�.
	// ansmat�� ��� ����
	// rep �ʱ�ȭ
	for (int i = 0; i < matsize; i++)
		for (int j = 0; j < matsize; j++)
			ansmat[i][j] = crimat[i][j];
	rep--;
	while (rep) {
		if (rep % 2) {
			matmul(true);
			rep--;
		}
		else {
			rep /= 2;
			matmul(false);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	if (n < m) {
		cout << 1 << '\n';
		return 0;
	}
	else if (n == m) {
		cout << 2 << '\n';
		return 0;
	}
	// a1 - am���� ���� ����.
	// am�� 2, �������� ��� 1
	// index�� 0~
	vl inivec(m, 1);
	inivec[m-1] = 2;
	crimat[0][0] = 1;
	crimat[0][m - 1] = 1;
	for (int i = 1; i < m; i++)
		crimat[i][i - 1] = 1;
	matpow(n - m);
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		ans += ansmat[0][i] * inivec[m - i - 1];
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}