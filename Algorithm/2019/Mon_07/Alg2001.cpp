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
int dp[101][1<<14], visit[101][1<<14]; // dp, visit
// 똑같은 위치에서 똑같은 visit이면 탐색x
int n,m,k;
vvp adj;
int gemis[101]; // 보석이 있는 index 저장
// 0-(k-1)
// 오름차순 저장
int solve(int pos, int gem){
	// pos에 막 도착 시 gem 소유 상태 => 앞으로 줍는 보석 최대개수 반환
	int& ret=dp[pos][gem];
	if(pos==1)
		goto rep; // 1로 왔던지 시작하던지 간에 주위 탐색
	if(ret!=-1)
		return ret;
	ret=0;
	// 현재 노드에서 주울지 안주울지 결정한다.
	rep:
	visit[pos][gem]=1;
	if(binary_search(gemis, gemis+k, pos)){
		int idx=lower_bound(gemis, gemis+k, pos)-gemis;
		for(auto p:adj[pos])
			if(__builtin_popcount(gem|(1<<idx))<=p.se&&!visit[p.fi][gem|(1<<idx)]&&!(gem&(1<<idx)))
				ret=max(ret,solve(p.fi,gem|(1<<idx))+1);
	}
	// 지나가는 루트
	for(auto p:adj[pos])
		if(!visit[p.fi][gem])
				ret=max(ret,solve(p.fi,gem));
	visit[pos][gem]=0;
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	memset(visit,0,sizeof(visit));
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
	cout<<solve(1,0)<<'\n';
	return 0;
}
/*dp : 

int solve(int pos, int gem) :

현재 위치가 pos일때, 그리고 지금 먹은 보석 상태가 visit일떄
앞으로 더 먹을 수 있는 보석 개수 반환

visit[pos][gem]도 설정해야함

탐색중에 visit[pos][gem]이 1이라면 탐색중단.(return 0)
*/
/* 반례 ;
5 6 4
2
3
4
5
1 2 4
2 3 1
3 4 2
4 5 3
5 2 4
2 4 1
*/