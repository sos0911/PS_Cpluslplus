// string을 쓰는 일반 문제풀이용 템플릿
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
	// 진료소 idx는 0부터 시작
	for (int i = 0; i < k; i++)
		cin >> inputarr[i];
	sort(inputarr, inputarr + k);
	ll low = 1, high = n * inputarr[0];
	// 이분탐색
	while (low <= high) {
		ll mid = (low + high) / 2;
		//cout<<"low : "<<low<<" high : "<<high<<" mid : "<<mid<<'\n';
		// 순차적으로 최대로 맞춰봄
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