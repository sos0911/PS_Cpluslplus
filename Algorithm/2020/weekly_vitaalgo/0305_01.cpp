// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 숫자로 변경하여 확인
	// 올림 주의
	string input, input2;
	cin >> input >> input2;
	// 숫자 변환
	int critime = stoi(input.substr(0, 2)) * 60 + stoi(input.substr(3));
	int stutime = stoi(input2.substr(0, 2)) * 60 + stoi(input2.substr(3));
	cout << (critime <= stutime && stutime < critime + 10) ? 1 : 0 << '\n';
	return 0;
}