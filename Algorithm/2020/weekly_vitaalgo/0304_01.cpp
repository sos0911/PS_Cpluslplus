// string을 쓰는 일반 문제풀이용 템플릿
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
	// input 제곱근까지의 수로 나눠본다.
	// 에라토스체네스는 O(nloglogn)이므로 절대 해결 불가능.
	// 해당 범위 내 소수들을 모두 찾으므로 더 걸린다..
	// 두 소수의 곱이거나 소수면 걸러진다.
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