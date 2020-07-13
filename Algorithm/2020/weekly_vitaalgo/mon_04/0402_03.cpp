// string�� ���� �Ϲ� ����Ǯ�̿� ���ø�
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpi;
typedef vector<pii> vpi;
int n, m;
vvpi adj;
bool visitarr[10001] = { false, };
struct comp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// ���� �˰���
	// �ּ� ���д� Ʈ��
	cin >> n >> m;
	// (��� idx, ����ġ) ����
	adj.assign(n + 1, vpi());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	// �ּ� ���д� Ʈ�� �����
	// (����� idx, ����ġ)
	// queue �ȿ��� ���д� Ʈ�� ��� -> ���д� Ʈ���� �ƴ� ��� ���� edge ����
	int ans = 0;
	priority_queue<pii, vector<pii>, comp> priq;
	priq.push({ 1,0 });
	while (!priq.empty()) {
		pii curnode = priq.top();
		priq.pop();
		// �̹� ����尡 ���д�Ʈ���� ���� ���� ���� �ִ�.
		// �̹� �տ��� ����ġ�� �� ���� ��θ� ã�Ƴ��� ���.
		if (visitarr[curnode.first])
			continue;
		visitarr[curnode.first] = true;
		ans += curnode.second;
		for(int i=0;i<adj[curnode.first].size();i++)
			if (!visitarr[adj[curnode.first][i].first]) {
				priq.push(adj[curnode.first][i]);
			}
	}
	cout << ans << '\n';
	return 0;
}