// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef long long ll;

int curx=0, cury=0;
int psize[3][2];
int minarea = INF;
int seq[3];

void make_comb(int idx) {
	// 수열만 만든다.
	if (idx == 3) {
		for (int i = 0; i < 3; i++)
			cout << seq[i] << " ";
		cout << '\n';
		// 비교
		curx = 0;
		for (int i = 0; i < 3; i++)
			curx += psize[i][seq[i]];
		cury = psize[0][(seq[0] + 1) % 2];
		for (int i = 0; i < 2; i++)
			cury = max(cury, psize[i + 1][(seq[i + 1] + 1) % 2]);
		minarea = min(minarea, curx * cury);
		return;
	}
	for (int i = 0; i < 2; i++) {
		seq[idx] = i;
		make_comb(idx + 1);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 경우는 두가지
	// 상자를 일렬로, 아니면 한 상자 | 나머지 두개 위아래로 포갠것
	// 90도 회전 2^3, 상자순서 3! 고려
	int noftc;
	cin >> noftc;
	for (int i = 0; i < noftc; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
				cin >> psize[j][k];

		curx = 0, cury = 0;
		
		// 상자 일렬
		make_comb(0);
	
		// 한 상자 | 나머지 두개 위아래
		for (int j = 0; j < 3; j++) {
			// j가 한 상자
			for (int k = 0; k < 2; k++) {
				curx = 0, cury = 0;
				curx += psize[j][k];
				cury += psize[j][(k + 1) % 2];
				curx += max(psize[(j + 1) % 3][0], psize[(j + 2) % 3][0]);
				cury = max(cury, psize[(j + 1) % 3][1] + psize[(j + 2) % 3][1]);
				minarea = min(minarea, curx * cury);

				curx = 0, cury = 0;
				curx += psize[j][k];
				cury += psize[j][(k + 1) % 2];
				curx += max(psize[(j + 1) % 3][0], psize[(j + 2) % 3][1]);
				cury = max(cury, psize[(j + 1) % 3][1] + psize[(j + 2) % 3][0]);
				minarea = min(minarea, curx * cury);

				curx = 0, cury = 0;
				curx += psize[j][k];
				cury += psize[j][(k + 1) % 2];
				curx += max(psize[(j + 1) % 3][1], psize[(j + 2) % 3][0]);
				cury = max(cury, psize[(j + 1) % 3][0] + psize[(j + 2) % 3][1]);
				minarea = min(minarea, curx * cury);

				curx = 0, cury = 0;
				curx += psize[j][k];
				cury += psize[j][(k + 1) % 2];
				curx += max(psize[(j + 1) % 3][1], psize[(j + 2) % 3][1]);
				cury = max(cury, psize[(j + 1) % 3][0] + psize[(j + 2) % 3][0]);
				minarea = min(minarea, curx * cury);
				
			}
		}

		cout << minarea << '\n';
	}
	return 0;
}