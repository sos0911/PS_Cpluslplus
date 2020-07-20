// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long nofp = 1, rep = 0;
	while (nofp < n) {
		nofp *= 2;
		rep++;
	}
	cout << rep << '\n';
	return 0;
}