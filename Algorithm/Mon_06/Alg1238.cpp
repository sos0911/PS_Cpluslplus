#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int,int>>> vvp;
typedef vector<pair<int,int>> vp;
typedef vector<int> v;
const int INF=1e9;
vvp adj;
v dp;
v dist;
void solve(int st){ // 시작점
	dist[st]=0;
	priority_queue<pair<int,int>> pq;
	// 최소 힙을 위해 자료형에 - 붙여 보관
	pq.push({st,0}); // 목표 노드, 거리
	while(!pq.empty()){
		int here=pq.top().first;
		int cost=-pq.top().second;
		pq.pop();
		for(auto& a:adj[here]){
			int next=a.first;
			int nextd=a.second+cost;
			if(dist[next]>nextd){
				dist[next]=nextd;
				pq.push({next, -nextd});
			}
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// dijkstra N+1번
	// tc : O(ElogV) 
	// 한 점에서 다른 점들까지의 최소거리
	// 갈때 1-n번, 올때 1번
	int n,m,x;
	cin>>n>>m>>x; // x번 마을에서 모임
	adj.assign(n+1, vp());
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	dp.assign(n+1, 0); // 각 학생마다 시간 저장
	dist.assign(n+1,INF);
	for(int i=1;i<=n;i++){
		solve(i); // 다익스트라
		dp[i]+=dist[x];
		fill(dist.begin(),dist.end(),INF);
	}
	solve(x); // x 다익스트라
	for(int i=1;i<=n;i++)
		dp[i]+=dist[i];
	int maxn=-1;
	for(int i:dp)
		maxn=max(maxn,i);
	cout<<maxn<<'\n';
	return 0;
}





