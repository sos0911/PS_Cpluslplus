// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
int inputarr[100001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// binary search
	cin >> n >> k;
	// ����� idx�� 0���� ����
	for (int i = 0; i < k; i++)
		cin >> inputarr[i];
	sort(inputarr, inputarr + k);
	ll low = 1, high = n * inputarr[0];
	// �̺�Ž��
	while (low <= high) {
		ll mid = (low + high) / 2;
		//cout<<"low : "<<low<<" high : "<<high<<" mid : "<<mid<<'\n';
		// ���������� �ִ�� ���纽
		ll left = n, idx = 0;
		while (left && idx < k) {
			left -= mid / inputarr[idx];
			idx++;
		}
		if (left <= 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << low << '\n';
	return 0;
}