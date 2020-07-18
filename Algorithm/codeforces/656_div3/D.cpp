// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
int n;
string input;
const int INF = 1e9;
int psum[131010][26] = { 0, }; // 0 - i idx���� ���ĺ��� ����.
int solve(int stidx, int edidx, int chidx) {

	// (stidx, edidx) �������� 'chidx'-good ����� ���� ���� cost ��ȯ
	if (stidx == edidx)
		return input[stidx] == (char)(chidx + 'a') ? 0 : 1;

	// �׻� ������ 2^n��
	int ans = INF;
	int mid = (stidx + edidx) / 2;

	int t1 = solve(mid + 1, edidx, chidx + 1), t2 = solve(stidx, mid, chidx + 1);

	ans = min(ans, mid - stidx + 1 - psum[mid][chidx] + t1);
	//cout << "solve : " << stidx << " " << edidx << " " << (char)(chidx + 'a') << " ::: "<< mid - stidx + 1 - psum[mid][chidx] << " " << t1<< '\n';
	ans = min(ans, edidx - mid - (psum[edidx][chidx] - psum[mid][chidx]) + t2);
	//cout << "solve : " << stidx << " " << edidx << " " << (char)(chidx + 'a') << " ::: " << edidx - mid - (psum[edidx][chidx] - psum[mid][chidx]) << " " << t2<< '\n';

	return ans;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin >> noft;
	for (int i = 0; i < noft; i++) {
		cin >> n;
		cin >> input;
		for (int j = 0; j < input.size(); j++)
			psum[j][input[j] - 'a'] = j ? psum[j - 1][input[j] - 'a'] + 1 : 1;
		cout << solve(0, n - 1, 0) << '\n';
		memset(psum, 0, sizeof(psum));
	}
	return 0;
}