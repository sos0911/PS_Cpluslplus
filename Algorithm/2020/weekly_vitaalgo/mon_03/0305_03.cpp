// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
int inputarr[200021];
// 아무리 커봤자 4배
ll tree[800084];
// 해당 범위 내 (idx, 값) 저장
pil maxtree[800084];
const int INF = 2e9;
int n, m;
ll init(int node, int st, int ed) {
	// (st,ed)구간을 tree[node]가 담당
	if (st == ed)
		return tree[node] = inputarr[st];
	else
		return tree[node] = init(node * 2, st, (st + ed) / 2) + init(node * 2 + 1, (st + ed) / 2 + 1, ed);
}
ll query(int node, int st, int ed, int left, int right) {
	// (left,right) => 찾는 구간
	if (left > ed || right < st)
		return 0;
	if (left <= st && ed <= right)
		return tree[node];
	return query(node * 2, st, (st + ed) / 2, left, right) + query(node * 2 + 1, (st + ed) / 2 + 1, ed, left, right);
}
// 요주의!
ll update(int node, int st, int ed, int idx) {
	if (idx < st || idx > ed)
		return tree[node];
	if (st == ed) {
		tree[node] /= 2;
		return tree[node];
	}
	return tree[node] = update(node * 2, st, (st + ed) / 2, idx) + update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx);
}
pil max_init(int node, int st, int ed) {
	if (st == ed)
		return maxtree[node] = { st, inputarr[st] };
	else {
		pil left_init = max_init(node * 2, st, (st + ed) / 2);
		pil right_init = max_init(node * 2+1, (st+ed)/2+1, ed);
		if (left_init.second >= right_init.second)
			return maxtree[node] = left_init;
		else
			return maxtree[node] = right_init;
	}
}
pil max_query(int node, int st, int ed, int left, int right) {
	// 해당 범위 내 (가장 큰놈 idx, 값) 반환
	// 여기서의 idx는 tree 내 idx이다.
	// 주의! 만약 양쪽 수가 같다면 무조건 idx 작은놈으로, 즉 left
	if (right < st || ed < left)
		return { -1, -INF };
	if (left <= st && ed <= right)
		return maxtree[node];

	pil left_ans = max_query(node * 2, st, (st + ed) / 2, left, right);
	pil right_ans = max_query(node * 2+1, (st+ed)/2+1, ed, left, right);

	if (left_ans.second >= right_ans.second)
		return left_ans;
	else
		return right_ans;
}
pil max_update(int node, int st, int ed, int idx) {
	if (idx < st || idx > ed)
		return maxtree[node];
	if (st == ed) {
		maxtree[node].second /= 2;
		return maxtree[node];
	}

	pil left_ans = max_update(node * 2, st, (st + ed) / 2, idx);
	pil right_ans = max_update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx);
	
	return maxtree[node] = left_ans.second >= right_ans.second ? left_ans : right_ans;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 펜윅 or segment tree
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> inputarr[i];
	init(1, 1, n);
	max_init(1, 1, n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			cout << query(1, 1, n, b, c) << '\n';
		}
		else {
			pil ans = max_query(1, 1, n, b, c);
			update(1, 1, n, ans.first);
			max_update(1, 1, n, ans.first);
		}
	}
	return 0;
}