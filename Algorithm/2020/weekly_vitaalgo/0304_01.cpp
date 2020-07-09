// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Isprime(ll num) {
	bool prime = true;
	for (ll i = 2; i * i <= num; i++)
		if (!(num % i)) {
			prime = false;
			break;
		}
	return prime;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll input;
	cin >> input;
	// input �����ٱ����� ���� ��������.
	// �����佺ü�׽��� O(nloglogn)�̹Ƿ� ���� �ذ� �Ұ���.
	// �ش� ���� �� �Ҽ����� ��� ã���Ƿ� �� �ɸ���..
	// �� �Ҽ��� ���̰ų� �Ҽ��� �ɷ�����.
	bool ans = true;
	for (ll i = 2; i * i <= input; i++)
		if (!(input % i)) {
			if (Isprime(i) && Isprime(input / i)) 
				ans = true;
			else
				ans = false;
			break;
		}
	cout << ans << '\n';
	return 0;
}