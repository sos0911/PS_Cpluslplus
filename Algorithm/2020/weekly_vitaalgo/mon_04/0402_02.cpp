// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
bool visitarr[1001][1001] = { false, };
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// bfs로 해봅시다.
	// (0,0)에서 시작
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;
	queue<pii> bfsq;
	visitarr[0][0] = true;
	bfsq.push({ 0,0 });
	int curtime = 1;
	while (!bfsq.empty()) {
		int len = bfsq.size();
		for (int i = 0; i < len; i++) {
			pii curstate = bfsq.front();
			bfsq.pop();
			
			if (curstate == make_pair(c, d)) {
				cout << curtime << '\n';
				return 0;
			}
			// 세 가지 선택지
			// 두 병에 동시에 버리거나 채우는 것도 고려. 단, (0,0)은 고려x
			if (!visitarr[0][curstate.second]) {
				visitarr[0][curstate.second] = true;
				bfsq.push({ 0,curstate.second });
			}
			if (!visitarr[curstate.first][0]) {
				visitarr[curstate.first][0] = true;
				bfsq.push({ curstate.first,0});
			}
			if (!visitarr[a][curstate.se]) {
				visitarr[a][curstate.se] = true;
				bfsq.push({ a,curstate.se });
			}
			if (!visitarr[curstate.first][b]) {
				visitarr[curstate.first][b] = true;
				bfsq.push({ curstate.first,b });
			}
			if (!visitarr[a][b]) {
				visitarr[a][b] = true;
				bfsq.push({ a,b });
			}
			int after_a, after_b;
			// b->a
			after_a = curstate.first + curstate.second > a ? a : curstate.first + curstate.second;
			after_b = curstate.first + curstate.second > a ? curstate.first + curstate.second - a : 0;
			if (!visitarr[after_a][after_b]) {
				visitarr[after_a][after_b] = true;
				bfsq.push({ after_a,after_b });
			}
			// a->b
			after_b = curstate.first + curstate.second > b ? b : curstate.first + curstate.second;
			after_a = curstate.first + curstate.second > b ? curstate.first + curstate.second - b : 0;
			if (!visitarr[after_a][after_b]) {
				visitarr[after_a][after_b] = true;
				bfsq.push({ after_a,after_b });
			}
		}
		curtime++;
	}
	cout << -1 << '\n';
	return 0;
}