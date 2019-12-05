// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
vvi child;
int n, tar, root, ans=0;
void solve(int here){
	int deg=0; // degree
	for(int next:child[here]){
		if(next==tar)
			continue;
		solve(next);
		deg++;
	}
	if(!deg)
		ans++;
}
int main(){
	scanf("%d", &n);
	child.assign(n, vi()); // 0번부터 시작
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		if(temp!=-1)
			child[temp].push_back(i);
		else
			root=i;
	}
	// 이미 부모와 자식이 확정났으므로, visit으로 탐색안해도됨
	scanf("%d", &tar);
	solve(root);
	printf("%d\n", ans);
	return 0;
}