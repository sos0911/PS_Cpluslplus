// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nofs;
	cin >> nofs;
	for (int i = 0; i < nofs; i++) {
		// 10문항
		bool check = true; // 만점을 받았는가?
		int input[10];
		for (int j = 0; j < 10; j++)
			cin >> input[j];
		for (int j = 0; j < 10; j++)
			if (input[j] != (j % 5) + 1) {
				check = false;
				break;
			}
		if (check)
			cout << i + 1 << '\n';
	}
	return 0;
}