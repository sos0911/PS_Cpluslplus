// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
int n,m,s,t;
const int INF=1e9;
vector<int> dist;
vector<vector<pii>> adj;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	dist.assign(n+1,INF);
	adj.assign(n+1,vector<pii>());
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	priority_queue<pii> pq; // max heap
	cin>>s>>t;
	dist[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int here=pq.top().fi;
		int cost=-pq.top().se;
		pq.pop();
		if(dist[here]<cost)
			continue;
		for(auto& p:adj[here]){
			int next=p.fi;
			int ncost=cost+p.se;
			if(dist[next]>ncost){
				dist[next]=ncost;
				pq.push({next,-ncost});
			}
		}
	}
	cout<<dist[t]<<'\n';
	return 0;
}