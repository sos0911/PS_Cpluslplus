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
const int MAXD=100001;
int ans=0;
int adj[MAXD]; // 각 vertex마다 엣지는 1개이다.
bool visit[MAXD], finish[MAXD];  // 방문 여부, 이 점에서 시작한 bfs 종료 여부
void dfs(int node){
	visit[node]=true;
	int next=adj[node];
		if(visit[next]&&!finish[next]){ // cycle 발생
			for(int temp=next;temp!=node;temp=adj[temp])
				ans++;
		}
		else
			dfs(next);
	finish[node]=true;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR(i,0,noft,1){
		int n;
		cin>>n;
		fill(visit, visit+n+1, false);
		fill(finish, finish+n+1, false);
		ans=0;
		// directed graph
		FOR(j,1,n+1,1)
			cin>>adj[j];
		FOR(j,1,n+1,1)
			if(!visit[j])
				dfs(j);
		cout<<n-ans<<'\n';
	}
	return 0;
}