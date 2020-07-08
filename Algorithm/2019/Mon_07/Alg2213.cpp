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
const int MAXD=10001, INF=2e9;
int n;
vi adj[MAXD];
int in[MAXD], dp[MAXD][2]; // 각 노드의 가중치
bool ans[MAXD][2], visit[MAXD];
vi ans2; // ans
int solve(int here, bool bepick){
	// 바로 전 노드를 pick했냐 안했냐에 따라 선택지 만들고 반환
	// 0은 선택x, 1은 선택
	// 확실히. 그때마다 visit으로 dfs하면서 하는 것보다
	// 먼저 dfs()로 tree child를 구해놓고 하는 게 좋은 것 같다.
	int& ret=dp[here][bepick];
	if(ret!=-1)
		return ret;
	// 선택x
	int nopick=0;
	for(int i:adj[here])
		if(!visit[i]){
			visit[i]=true;
			nopick+=solve(i,false);
			visit[i]=false;
		}
	// 선택
	int pick=(bepick?-INF:in[here]);
	if(!bepick){
	for(int i:adj[here])
		if(!visit[i]){
			visit[i]=true;
			pick+=solve(i,true);
			visit[i]=false;
		}
	}
	ans[here][bepick]=(pick>=nopick? true:false); 
	return ret=max(nopick,pick);
}
// tracking 함수 중단
void tracking(int here, bool bepick){
	bool& ret=ans[here][bepick];
	// ans는 선수조건이 주어질 시 here을 픽하는게 이득인지 아닌지 계산한 것
	if(ret){
		ans2.push_back(here);
		for(int i:adj[here])
			if(!visit[i]){
			visit[i]=true;
			tracking(i,true);
			visit[i]=false;
		}
	}
	else
		for(int i:adj[here])
			if(!visit[i]){
			visit[i]=true;
			tracking(i,false);
			visit[i]=false;
		}	
}
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>n;
	FOR(i,1,n+1,1)
		cin>>in[i];
	FOR(i,0,n-1,1){ // tree의 edge 개수는 n-1
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(visit,visit+n+1,false);
	memset(dp,-1, sizeof(dp));
	visit[1]=true; // start
	cout<<solve(1,false)<<'\n';
	tracking(1,false);
	sort(ans2.begin(), ans2.end());
	for(int i:ans2)
		cout<<i<<" ";
	cout<<'\n';
	return 0;
}