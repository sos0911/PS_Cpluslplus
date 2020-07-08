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
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d
int n, idx=1;
int cmap[101][101]; // 1부터
int visit[101][101]; // 1부터
void dfs(int node){ 
	//visit[idx][node]=true;
	FOR(i,1,n+1,1)
		if(cmap[node][i]==1&&!visit[idx][i]){
			visit[idx][i]=true;
			dfs(i);
		}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR(i,1,n+1,1)
		FOR(j,1,n+1,1)
			cin>>cmap[i][j];
	FOR(i,1,n+1,1)
		fill(visit[i], visit[i]+n+1, 0);
	FOR(i,1,n+1,1){
		idx=i; // index
		dfs(i); // i에 대해 dfs를 돌림
	}
	FOR(i,1,n+1,1){
		FOR(j,1,n+1,1)
			cout<<visit[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}