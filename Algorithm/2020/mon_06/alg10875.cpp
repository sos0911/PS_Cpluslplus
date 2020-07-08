// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
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
	// �� �ȿ� �ִ��� Ȯ��
	// �ۿ� �ִٸ� true
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
	// (a->b), (c->d) ���� �� ���� �Ǻ�
	// ���� ���ݺ��� �������� �������̸� skip
	if (a == d)
		return 0;
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		// �ƿ� ������ skip.
		// �ٵ�.. �������� �� ������ ��쵵 ����..

		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return (c <= b && a <= d)? 2:0;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ���� ������ �ڸ��� ���� ��ü�� ���´�.
	int mapsize;
	cin >> mapsize;
	int n;
	cin >> n;
	vector<pic> rotateinfo(n, { 0, 'A' });
	for (int i = 0; i < n; i++) {
		cin >> rotateinfo[i].fi >> rotateinfo[i].se;
	}

	rotateinfo.push_back({ 2e9, 'L' }); // ������ ó��

	// idx Ŀ������ L ����, ������ R ����
	pii dir[] = { {1,0}, {0,1}, {-1,0},{0,-1} };
	vector<pll> trackpoint; // �������� Ű������ ��ǥ ����
	int curdiridx = 0; // ������� idx
	pll curpos = { 0,0 }; // ���� ��ġ
	ll curlen = 0;// �ð� ��� ����


	trackpoint.reserve(n);
	// pii[] ����. ���ο� ��ġ�� �߰��� ������ �̰� ������ �������� Ȥ�� 
	// ����� ��ġ ���̷� ���������� ����
	trackpoint.push_back({ 0,0 }); // ������


	for (int i = 0; i < n+1; i++) {
		curpos.first += (ll)dir[curdiridx].first * rotateinfo[i].fi;
		curpos.second += (ll)dir[curdiridx].second * rotateinfo[i].fi;
	
		// ���� ��ġ�°�?
		if (!(trackpoint.size() == 1)) {
			bool Isinter = false;
			ll minlen = 2e9;
			int tracklen = trackpoint.size();
			for (int j = 0; j < tracklen-1; j++) {
				pii befpos = trackpoint[trackpoint.size() - 1];
				// ccw ����, intersect
				// �ٵ� intersec�Ǵ� �͵� �߿����� ���� ����� �Ͱ�,,,,
				int interval = intersect(befpos, curpos, trackpoint[j], trackpoint[j + 1]);
				if (interval) {
					Isinter = true;
					// ���� ������ �� �ð� �߰�.
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
		
		// ���� ����
		curlen += rotateinfo[i].first;
		if (rotateinfo[i].second == 'L')
			curdiridx = (curdiridx + 1) % 4;
		else
			curdiridx = (curdiridx - 1)<0? curdiridx-1+4: curdiridx-1;

		trackpoint.push_back(curpos);
	}
	
	return 0;
}