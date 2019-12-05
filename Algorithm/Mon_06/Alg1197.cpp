#include <iostream>
#include <queue> // 우선순위큐
#include <vector>
#include <functional>
using namespace std;
typedef vector<vector<pair<int,int>>> vvpii;
typedef vector<pair<int,int>> vpii;
typedef vector<bool> vb;
typedef pair<int,int> pii;
// 프림 algorithm
struct comp{
	bool operator()(pii& p1, pii& p2){
		// false일때 바꾼다.
		return p1.second==p2.second? p1.first<p2.first:p1.second>p2.second;
		// less<int>가 기본. pq는 뒤에 있는게 밖으로 튀어나오는 모양..
		// default는 큰 게 우선순위가 크다.
		// greater<int>로 해야 오름차순 ㅅㅂ..
	}	
};
int prim(int st, vvpii& adj, vb& visit){
	// st에 관련된 노드들을 박아넣는다
	priority_queue<pii, vector<pii>, comp> pq;
	visit[st]=true;
	for(int i=0;i<adj[st].size();i++)
		pq.push(adj[st][i]); // 복사
	int ans=0;
	while(!pq.empty()){
		auto temp=pq.top();
		pq.pop();
		if(visit[temp.first]) // 이미 방문한 노드=>cycle 생성
			continue;
		visit[temp.first]=true;
		ans+=temp.second;
		for(int i=0;i<adj[temp.first].size();i++)
			pq.push(adj[temp.first][i]);
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int v,e;
	cin>>v>>e;
	vvpii adj(v+1, vpii()); // 노드가 v개므로, index 1-
	vb visit(v+1, false);
	int a,b,c;
	for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b, c}); // pair(상대노드, 가중치)
		adj[b].push_back({a, c});
	}
	cout<<prim(1, adj, visit)<<'\n'; // 1번 노드가 start
	return 0;
}