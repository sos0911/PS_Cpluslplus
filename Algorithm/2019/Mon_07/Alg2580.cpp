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
int cmap[9][9]; // 0-
int visit[3][9];
vpi tar; int tarlen;
// rvisit,cvisit,recvisit
// bitmasking
bool find(int idx){
 // tar idx일때 backtracking
	if(idx==tarlen)
		return true;
	int i=tar[idx].fi;
	int j=tar[idx].se;
	FOR(n,1,10,1)
		if(!(visit[0][i]&(1<<n))&&!(visit[1][j]&(1<<n))&&!(visit[2][(i/3)*3+(j/3)]&(1<<n))){
			cmap[i][j]=n; // 덮어씌우므로 undo x
			visit[0][i]|=1<<n;
			visit[1][j]|=1<<n;
			visit[2][(i/3)*3+(j/3)]|=1<<n;
			if(find(idx+1))
				return true;
			visit[0][i]^=1<<n;
			visit[1][j]^=1<<n;
			visit[2][(i/3)*3+(j/3)]^=1<<n;
		}
	return false;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	FOR(i,0,9,1)
		FOR(j,0,9,1){
			cin>>cmap[i][j];
		if(cmap[i][j]==0)
			tar.push_back({i,j}); // (r,c)
		else{
			visit[0][i]|=1<<cmap[i][j];
			visit[1][j]|=1<<cmap[i][j];
			visit[2][(i/3)*3+(j/3)]|=1<<cmap[i][j];
		}
	}
	tarlen=tar.size();
	find(0);
	FOR(i,0,9,1){
		FOR(j,0,9,1)
			cout<<cmap[i][j]<<" ";
		cout<<'\n';	
	}
	return 0;
}