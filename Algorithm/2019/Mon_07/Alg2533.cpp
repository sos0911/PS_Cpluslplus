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
const int maxD=1000001;
const int INF=1e9;
// 양방향 graph
int n;
vi adj[maxD], child[maxD];
int dp[maxD][2]; // 선택하느냐 안하느냐
bool visit[maxD];
bool dfs(int here){ // child 탐색
	visit[here]=true;
	for(int next:adj[here])
		if(!visit[next]){
			child[here].push_back(next);
			dfs(next);
		}
}
int solve(int here, bool bead){
	// 부모가 ad인지 아닌지에 주어질 때 here 포함 아래 서브트리 내 필요한 
	// 최소 어답터 수 구함
	// 0이면 false, 1이면 true
	int& ret=dp[here][bead];
	if(ret!=-1)
		return ret;
	// 두 가지 선택지
	// bead가 false면 무조건 pick
	int pick=1, npick=INF;
	for(int next:child[here])
		pick+=solve(next,true);
	if(bead){
		npick=0;
		for(int next:child[here])
			npick+=solve(next,false);
	}
	return ret=min(pick,npick);
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR(i,0,n-1,1){
		int a,b;
		cin>>a>>b;
		// 양방향
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1); // 1에서 시작하는 dfs
	memset(dp,-1,sizeof(dp)); // byte 크기로 채움
	cout<<solve(1,true)<<'\n';
	return 0;
}