// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ���ڷ� �����Ͽ� Ȯ��
	// �ø� ����
	string input, input2;
	cin >> input >> input2;
	// ���� ��ȯ
	int critime = stoi(input.substr(0, 2)) * 60 + stoi(input.substr(3));
	int stutime = stoi(input2.substr(0, 2)) * 60 + stoi(input2.substr(3));
	cout << (critime <= stutime && stutime < critime + 10) ? 1 : 0 << '\n';
	return 0;
}