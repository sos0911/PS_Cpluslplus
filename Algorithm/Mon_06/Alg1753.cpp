	#include <bits/stdc++.h>
	using namespace std;
 	typedef vector<vector<pair<int,int>>> vvp;
	typedef vector<pair<int,int>> vp;
	typedef vector<int> vi;
	const int INF=1e9;
	int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// dijkstra c++
		// tc : Elog(E)=Elog(v)
		// dist[] = inf
		int v,e,k;
		cin>>v>>e>>k;
		vvp adj(v+1, vp());
		vi dist(v+1, INF);
		dist[k]=0; // 시작점
		priority_queue<pair<int,int>> pq; // 최대 힙
		pq.push({0,k}); // (dist, 목표 노드)
		for(int i=0;i<e;i++){
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back({b,c}); // 상대 노드, 거리
		}
		while(!pq.empty()){
			int cost=-pq.top().first; // here까지 가는 거리
			int here=pq.top().second; // here
			pq.pop();
			for(auto& a:adj[here]){ // 변경x므로 참조자 유리
				int next=a.first;
				int nextd=a.second+cost;
				if(dist[next]>nextd){ // 갱신 가능한 경우 갱신
					// if문 해당 x 경우 무시
					dist[next]=nextd;
					pq.push({-nextd, next});
					// 갱신되었으므로 탐색이 필요 -> push
				}
			}
		}
		for(int i=1;i<=v;i++)
			if(dist[i]==INF)
				cout<<"INF"<<'\n';
		else
			cout<<dist[i]<<'\n';
	return 0;
	}