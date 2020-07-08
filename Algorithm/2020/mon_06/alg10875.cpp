// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
typedef pair<ll, ll> pll;


template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << "("<< pai.first << ' ' << pai.second<<")";
	return os;
}

bool check(pii curpos, int mapsize) {
	// 맵 안에 있는지 확인
	// 밖에 있다면 true
	return curpos.first < -mapsize || curpos.first > mapsize || curpos.second < -mapsize || curpos.second > mapsize;
}

ll ccw(pii a, pii b, pii c) {
	ll op = (ll)a.first * b.second + (ll)b.first * c.second + (ll)c.first * a.second;
	op -= (ll)a.second * b.first + (ll)b.second * c.first + (ll)c.second * a.fi;
	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

int intersect(pii a, pii b, pii c, pii d) {
	// (a->b), (c->d) 선분 간 교차 판별
	// 만약 지금벡터 시작점이 교차점이면 skip
	if (a == d)
		return 0;
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		// 아예 같으면 skip.
		// 근데.. 직각으로 딱 만나는 경우도 포함..

		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return (c <= b && a <= d)? 2:0;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 뱀이 지나간 자리는 뱀의 몸체가 남는다.
	int mapsize;
	cin >> mapsize;
	int n;
	cin >> n;
	vector<pic> rotateinfo(n, { 0, 'A' });
	for (int i = 0; i < n; i++) {
		cin >> rotateinfo[i].fi >> rotateinfo[i].se;
	}

	rotateinfo.push_back({ 2e9, 'L' }); // 마지막 처리

	// idx 커질수록 L 방향, 역순은 R 방향
	pii dir[] = { {1,0}, {0,1}, {-1,0},{0,-1} };
	vector<pll> trackpoint; // 지나가는 키프레임 좌표 저장
	int curdiridx = 0; // 현재방향 idx
	pll curpos = { 0,0 }; // 현재 위치
	ll curlen = 0;// 시간 경과 길이


	trackpoint.reserve(n);
	// pii[] 유지. 새로운 위치를 추가할 때마다 이게 밖으로 나가는지 혹은 
	// 저장된 위치 사이로 지나가는지 추적
	trackpoint.push_back({ 0,0 }); // 시작점


	for (int i = 0; i < n+1; i++) {
		curpos.first += (ll)dir[curdiridx].first * rotateinfo[i].fi;
		curpos.second += (ll)dir[curdiridx].second * rotateinfo[i].fi;
	
		// 뱀이 겹치는가?
		if (!(trackpoint.size() == 1)) {
			bool Isinter = false;
			ll minlen = 2e9;
			int tracklen = trackpoint.size();
			for (int j = 0; j < tracklen-1; j++) {
				pii befpos = trackpoint[trackpoint.size() - 1];
				// ccw 수행, intersect
				// 근데 intersec되는 것들 중에서도 가장 가까운 것과,,,,
				int interval = intersect(befpos, curpos, trackpoint[j], trackpoint[j + 1]);
				if (interval) {
					Isinter = true;
					// 죽을 때까지 간 시간 추가.
					if (trackpoint[j].first == trackpoint[j + 1].first) {
						if (interval == 2) {
							if (curpos == trackpoint[j])
								minlen = min(minlen, abs(curpos.first - befpos.first + curpos.second - befpos.second));
							else
								minlen = min(minlen, abs(befpos.se - trackpoint[j].se));
						}
						else
							minlen = min(minlen, abs(befpos.first - trackpoint[j].first));
					}
					else {
						if (interval == 2) {
							if (curpos == trackpoint[j])
								minlen = min(minlen, abs(curpos.first - befpos.first + curpos.second - befpos.second));
							else
								minlen = min(minlen, abs(befpos.first - trackpoint[j].first));
						}
						else
							minlen = min(minlen, abs(befpos.se - trackpoint[j].se));
					}
				}
			}
			if (Isinter) {
				curlen += minlen;
				cout << curlen << '\n';
				return 0;
			}
		}

		if (check(curpos, mapsize)) {
			if (curdiridx == 0)
				curlen += abs(mapsize - trackpoint[trackpoint.size() - 1].fi) + 1;
			else if(curdiridx == 1)
				curlen += abs(mapsize - trackpoint[trackpoint.size() - 1].se) + 1;
			else if(curdiridx == 2)
				curlen += abs(-mapsize - trackpoint[trackpoint.size() - 1].fi) + 1;
			else
				curlen += abs(-mapsize - trackpoint[trackpoint.size() - 1].se) + 1;
			cout << curlen << '\n';
			return 0;
		}
		
		// 정보 갱신
		curlen += rotateinfo[i].first;
		if (rotateinfo[i].second == 'L')
			curdiridx = (curdiridx + 1) % 4;
		else
			curdiridx = (curdiridx - 1)<0? curdiridx-1+4: curdiridx-1;

		trackpoint.push_back(curpos);
	}
	
	return 0;
}