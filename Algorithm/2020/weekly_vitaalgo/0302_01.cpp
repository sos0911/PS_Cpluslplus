// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// map ���
	map<int, int> count; // (��ȣ, ����)
	int n, m;
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		auto tar_itr = count.find(temp);
		if (tar_itr == count.end())
			count.insert({ temp, 1 });
		else
			tar_itr->second++;
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		auto tar_itr = count.find(temp);
		cout << (tar_itr != count.end() ? count.find(temp)->second : 0) << " ";
	}
	return 0;
}