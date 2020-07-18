// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin >> noft;
	for (int i = 0; i < noft; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int maxd = max({ x,y,z });
		if ((x == y && y > z) || (y == z && z > x) || (z == x && x > y)) {
			cout << "YES" << '\n';
			cout << max({ x,y,z }) << " " << min({ x,y,z }) << " " << min({ x,y,z }) << '\n';
		}
		else if (x == y && y == z) {
			cout << "YES" << '\n';
			cout << max({ x,y,z }) << " " << min({ x,y,z }) << " " << min({ x,y,z }) << '\n';
		}
		else
			cout << "NO" << '\n';
	}
	return 0;
}