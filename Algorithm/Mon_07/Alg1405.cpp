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
int per[4]; // EWSN
int visit[30][30]; // 1이면 visit
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
db solve(int cnt, db p, int r, int c){
	// 지금까지 cnt 수행할 시 앞으로 갈 수 있는 단순확률 반환(p=1)
	if(cnt==n)
		return (db)1;
	db temp=0;
	FOR(i,0,4,1){
		int nextr=r+dir[i][0];
		int nextc=c+dir[i][1];
		if(!visit[nextr][nextc]){
			visit[nextr][nextc]=1;
			temp+=((db)per[i]/100)*solve(cnt+1,p*((db)per[i]/100),nextr,nextc);
			visit[nextr][nextc]=0;
		}
	}
	return temp;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout.precision(15);
	cin>>n;
	FOR(i,0,4,1)
		cin>>per[i];
	memset(visit,0,sizeof(visit));
	visit[14][14]=true;
	cout<<solve(0,1,14,14)<<'\n';
	return 0;
}
// 10^-9;;
