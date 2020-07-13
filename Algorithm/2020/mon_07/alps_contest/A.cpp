// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string input;
	cin >> input;
	string criarr[3] = { "SSH", "SHS", "HSS" };
	int score = 0;
	for (int i = 0; i < n - 2; i++) {
		string token = input.substr(i, 3);
		for (int j = 0; j < 3; j++) {
			if (!token.compare(criarr[j])) {
				score += 3-j;
				break;
			}
		}
	}
	cout << score << '\n';
	return 0;
}