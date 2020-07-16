// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ������ ��Ȯ���� ���� ���ϰڴ�..
	// n^2�� �ϴ� ����Ž��
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// lcs[i][j] : a�� 1~i��° ����, b�� 1~j��° ���ڸ� ������ lcs ����
	// lcs�� ���̴� idx�� ���� string idx�� ���̰� �ִ�. ����!
	int lcs[1001][1001] = { 0, };
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
	cout << lcs[n][m] << '\n';
	return 0;
}