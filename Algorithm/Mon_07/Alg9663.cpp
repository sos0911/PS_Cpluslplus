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
int visit[3][31]; 
// 열 검사, y+x 검사, (n-1)+(y-x) 검사
// 1이면 visit
int n,ans=0;
void find(int r){
	// 지금 보는 행 idx
	if(r==n)
		ans++;
	// back
	FOR(c,0,n,1)
		if(!visit[0][c]&&!visit[1][r+c]&&!visit[2][(n-1)+(r-c)]){
			visit[0][c]^=1;
			visit[1][r+c]^=1;
			visit[2][n-1+(r-c)]^=1;
			find(r+1);
				visit[0][c]^=1;
			visit[1][r+c]^=1;
			visit[2][n-1+(r-c)]^=1;
		}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	memset(visit,0,sizeof(visit));
	find(0);
	cout<<ans<<'\n';
	return 0;
}