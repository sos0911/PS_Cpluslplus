// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
string input;
const int INF = 1e9;
int solve(int stidx, int edidx, int chidx) {

	// (stidx, edidx) 구간에서 'chidx'-good 만드는 가장 적은 cost 반환
	if (stidx == edidx)
		return input[stidx] == (char)(chidx + 'a') ? 0 : 1;

	int mid = (stidx + edidx) / 2;

	int l_half = mid - stidx + 1 - count(input.begin() + stidx, input.begin() + mid + 1, (char)(chidx + 'a')) + solve(mid + 1, edidx, chidx + 1);
	int r_half = edidx - mid - count(input.begin() + mid + 1, input.begin() + edidx + 1, (char)(chidx + 'a')) + solve(stidx, mid, chidx + 1);

	return min(l_half, r_half);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin >> noft;
	for (int i = 0; i < noft; i++) {
		cin >> n;
		cin >> input;
		cout << solve(0, n - 1, 0) << '\n';
	}
	return 0;
}