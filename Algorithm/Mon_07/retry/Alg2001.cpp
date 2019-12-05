#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int n,m,k;
vvp adj;
int gemis[101]; // 보석이 있는 index 저장
int maxn[101]; // 각 섬에서 탐색이 끝날 시 얻는 최대 보석
// 0-(k-1)
// 오름차순 저장
// MCMF 필요 --> 중단
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	memset(maxn,0,sizeof(maxn));
	FOR(i,0,k,1){
		int temp;
		cin>>temp;
		gemis[i]=temp; // 0부터
	}
	sort(gemis, gemis+k);
	adj.assign(101,vpi());
	FOR(i,0,m,1){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c}); // 상대 노드 번호, 보석 limit
		adj[b].push_back({a,c});
	}
	// bfs
	// 싱태 : 해당 섬에 막 도착 시 상태
	queue<pii> bfsq;
	bfsq.push({1,0}); // 현재 노드, 보석 상태
	while(!bfsq.empty()){
		auto here=bfsq.front();
		bfsq.pop();
		cout<<"here : "<<here.fi<<" "<<bitset<32>(here.se)<<'\n';
		// 없을 때 주워봄
		if(binary_search(gemis, gemis+k, here.fi)){
			int idx=lower_bound(gemis, gemis+k, here.fi)-gemis;
			int ngem=__builtin_popcount(here.se|(1<<idx));
			if(!(here.se&(1<<idx)))
			for(auto next:adj[here.fi])
				if(ngem<=next.se&&maxn[next.fi]<ngem){
					maxn[next.fi]=ngem;
					bfsq.push({next.fi,here.se|(1<<idx)});
					cout<<"added : "<<next.fi<<" "<<bitset<32>(here.se|(1<<idx))<<'\n';
				}
		}
		// pass
		int ngem=__builtin_popcount(here.se);
		for(auto next:adj[here.fi])
			if(ngem<=next.se&&maxn[next.fi]<ngem){
					maxn[next.fi]=ngem;
					bfsq.push({next.fi,here.se});
				cout<<"added : "<<next.fi<<" "<<bitset<32>(here.se)<<'\n';
				}
	}
	cout<<maxn[1]<<'\n';
	return 0;
}