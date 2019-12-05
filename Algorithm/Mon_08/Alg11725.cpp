// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int parent[100001]; // 1-100000
bool visit[100001]={};
vvi adj;
int n;
int main(){
	scanf("%d", &n);
	adj.assign(n+1,vi());
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// bfs
	queue<int> bfsq;
	bfsq.push(1);
	visit[1]=true;
	while(!bfsq.empty()){
		int here=bfsq.front();
		bfsq.pop();
		for(int next:adj[here])
			if(!visit[next]){
				parent[next]=here;
				visit[next]=true;
				bfsq.push(next);
			}
	}
	for(int i=2;i<=n;i++)
		printf("%d\n", parent[i]);
	return 0;
}