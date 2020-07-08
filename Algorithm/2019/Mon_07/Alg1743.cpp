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
int cmap[101][101];
bool visit[101][101];
int dir[][2]{{1,0},{-1,0},{0,1},{0,-1}};
int n,m,k;
int dfs(int y, int x){ // 컴포넌트 크기 반환
	int ret=1; // 자기 자신
	visit[y][x]=true;
	FOR(i,0,4,1){
		int nexty=y+dir[i][0];
		int nextx=x+dir[i][1];
		if(nexty>0&&nexty<=n&nextx>0&&nextx<=m&&!visit[nexty][nextx]&&cmap[nexty][nextx]==1)
				ret+=dfs(nexty,nextx);
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	FOR(i,0,n+1,1)
		fill(cmap[i], cmap[i]+m+1, 0); // 0으로 초기화
	FOR(i,0,k,1){ // (1,1)부터 시작
		int y,x;
		cin>>y>>x;
		cmap[y][x]=1;
	}
	FOR(i,0,n+1,1)
		fill(visit[i], visit[i]+m+1, false);
	int ret=0;
	FOR(i,1,n+1,1)
		FOR(j,1,m+1,1)
			if(cmap[i][j]==1&&!visit[i][j])
				ret=max(ret,dfs(i,j));
	cout<<ret<<'\n';
	return 0;
}