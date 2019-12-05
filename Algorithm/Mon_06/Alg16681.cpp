#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int,int>>> vvp;
typedef vector<pair<int,int>> vp;
typedef vector<long long> vl;
typedef long long ll;
vvp adj; 
vl hei;
vl dist;
vl ans; // 정답 벡터
const ll INF=1e15;
int n,m,d,e;
void dijk(int st){
	priority_queue<pair<ll,int>> pq;
	vector<bool> visit(n+1, false);
	pq.push({0,st});
	while(!pq.empty()){
		ll cost=-pq.top().first;
		int here=pq.top().second;
		pq.pop();
		if(!visit[here]){
		for(auto& a:adj[here]){
			int next=a.first;
			ll nextd=cost+a.second;
			if(hei[here]<hei[next]&&dist[next]>nextd){
				dist[next]=nextd;
				pq.push({-nextd, next});
			}
		}
			visit[here]=true;
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// DIJKSTRA
	cin>>n>>m>>d>>e;
	adj.assign(n+1, vp());
	//(상대 노드, 경로 길이) 저장
	hei.assign(n+1,0); // 0으로 초기화, 위치저장
	ans.assign(n+1,0); 
	dist.assign(n+1,INF);
	ll input;
	for(int i=1;i<=n;i++){
		cin>>input;
		hei[i]=input;
	}
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dijk(1);
	for(int i=2;i<n;i++)
		ans[i]+=dist[i]; // 가는 경로 존재
	fill(dist.begin(),dist.end(),INF);
	dijk(n);
	for(int i=2;i<n;i++)
		if(ans[i]!=INF)
		ans[i]+=dist[i]; // 오는 경로 존재
	ll maxn=-INF;
	for(int i=2;i<n;i++)
		if(ans[i]<INF)
			maxn=max(maxn,hei[i]*e-ans[i]*d);
	if(maxn==-INF)
		cout<<"Impossible"<<'\n';
	else
		cout<<maxn<<'\n';
	return 0;
}
// https://hello70825.tistory.com/80
// https://m.blog.naver.com/CommentList.nhn?blogId=kks227&logNo=220796029558