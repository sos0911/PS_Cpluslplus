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
int n;
int dir[][2]{{1,0},{-1,0},{0,1},{0,-1}};
char cmap[101][101]; // (0,0)부터
bool visit[101][101];
void ndfs(int y, int x){
	visit[y][x]=true;
	FOR(i,0,4,1){
		int nexty=y+dir[i][0];
		int nextx=x+dir[i][1];
		if(nexty>=0&&nexty<n&&nextx>=0&&nextx<n&&!visit[nexty][nextx]&&cmap[nexty][nextx]==cmap[y][x])
			ndfs(nexty,nextx);
	}
}
void ddfs(int y, int x){
	visit[y][x]=true;
	FOR(i,0,4,1){
		int nexty=y+dir[i][0];
		int nextx=x+dir[i][1];
		if(nexty>=0&&nexty<n&&nextx>=0&&nextx<n&&!visit[nexty][nextx]){
			if((cmap[y][x]=='R'||cmap[y][x]=='G')&&(cmap[nexty][nextx]=='R'||cmap[nexty][nextx]=='G'))
				ddfs(nexty,nextx);
			else if(cmap[y][x]==cmap[nexty][nextx])
				ddfs(nexty,nextx);
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR(i,0,n,1){
		string in;
		cin>>in;
		FOR(j,0,n,1)
			cmap[i][j]=in[j];
	}
	// 정상인
	FOR(i,0,n,1)
		fill(visit[i],visit[i]+n,false);
	int nret=0;
	FOR(i,0,n,1)
		FOR(j,0,n,1)
			if(!visit[i][j]){
				nret++;
				ndfs(i,j);
			}
	// 색맹
	FOR(i,0,n,1)
		fill(visit[i],visit[i]+n,false);
	int dret=0;
	FOR(i,0,n,1)
		FOR(j,0,n,1)
			if(!visit[i][j]){
				dret++;
				ddfs(i,j);
			}
	cout<<nret<<" "<<dret<<'\n';
	return 0;
}