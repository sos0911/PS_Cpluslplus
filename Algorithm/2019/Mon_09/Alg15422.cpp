// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF=1e10;
int n,m,f,s,t;
struct Info{
 ll cost;
int node;
 bool used; // 티켓을 사용했는가?
	Info(ll cost, int node, bool used):cost(cost),node(node),used(used){}
};
ll dist[50001];
vector<vector<pii>> adj;
vector<vector<int>> flight; // 비행기로 갈 수 있는 도시
struct comp{
	bool operator()(Info& a, Info& b){
		return a.cost<b.cost;
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>f>>s>>t;
	fill(dist,dist+n,INF); // 처음에는 INF로 초기화
	dist[s]=0;
	adj.assign(n,vector<pii>());
	flight.assign(n,vector<int>());
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	for(int i=0;i<f;i++){
		int a,b;
		cin>>a>>b;
		flight[a].push_back(b);
	}
	//  dijkstra
	priority_queue<Info, vector<Info>, comp> pq;
	// 최대 힙
	pq.push(Info(0,s,false));
	while(!pq.empty()){
		ll cost=-pq.top().cost;
		int here=pq.top().node;
		bool used=pq.top().used;
		pq.pop();
		if(dist[here]<cost)
			continue;
		// 여기에 =을 붙여버리면
		// 추가하고 queue에 들어왔던 게 더이상 진행을 못함 ㅎㅎ
		for(auto& p:adj[here]){
			ll ncost=cost+p.se;
			int next=p.fi;
			if(dist[next]>ncost){
				dist[next]=ncost;
				pq.push(Info(-ncost,next,false));
			}
		}
		if(used)
			continue;
		for(auto& next:flight[here]){
			if(dist[next]>cost){
				dist[next]=cost;
				pq.push(Info(-cost,next,true));
			}
		}
	}
	cout<<dist[t]<<'\n';
	return 0;
}