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
	int len = input.size();
	int nofchar = 0;

	for (int i = 0; i < len; i++)
		if (input[i] == '@')
			nofchar++;

	int curnofchar = 0, befcharidx = len;
	list<string> behalf, afhalf;
	//behalf.reserve(n / 2);
	//afhalf.reserve(n / 2);
	int i = len - 1;
	for (; i >= 0; i--) {
		if (input[i] == '@') {
			if (curnofchar % 2)
				behalf.push_front(input.substr(i + 1, befcharidx - i - 1));
			else
				afhalf.push_front(input.substr(i + 1, befcharidx - i - 1));
			befcharidx = i;
			curnofchar++;
		}
	}
	if (curnofchar % 2)
		behalf.push_front(input.substr(i + 1, befcharidx - i - 1));
	else
		afhalf.push_front(input.substr(i + 1, befcharidx - i - 1));
	//reverse(behalf.begin(), behalf.end());
	for (auto itr = --behalf.end(); itr != --behalf.begin(); itr--) {
		string temp = *itr;
		reverse(temp.begin(), temp.end());
		cout << temp;
	}
	for (auto i : afhalf)
		cout << i;
	cout << '\n';
	return 0;
}