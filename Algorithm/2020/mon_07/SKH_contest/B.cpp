// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
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