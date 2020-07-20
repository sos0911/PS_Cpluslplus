// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	string mail = "@korea.ac.kr";
	int curstidx = 0;
	int maxlen = 0; string cache = "";
	while (true) {
		int pos = input.find(mail, curstidx);
		if (pos == string::npos)
			break;
		else {
			int edidx = pos-1;
			while (edidx >= 0 && input[edidx] != '!' && input[edidx] != '$' && input[edidx] != '@' && input[edidx] != '#' && input[edidx] != '.')
				edidx--;
			if (pos - edidx - 1 > maxlen) {
				maxlen = pos - edidx - 1;
				cache = input.substr(edidx + 1, maxlen);
			}
		}
		curstidx = pos + mail.size();
	}
	if (maxlen)
		cout << cache + mail << '\n';
	else
		cout << "" << '\n';
	
	return 0;
}