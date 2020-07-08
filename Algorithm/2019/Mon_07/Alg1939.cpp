#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<pii> vpi;
typedef vector<vector<pii>> vvp;
// 이분탐색 -> retry
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vvp adj(n+1, vpi()); // 임시객체 생성 방법
	// 섬 번호 : 1-
	// (상대 노드, 가중치)
	FOR1(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	int st,ed;
	cin>>st>>ed;
	queue<pii> bfsq; // (지금 노드, 중량값)
	int visit[n+1]; // 저장된 값보다 값이 커야 통과
	memset(visit,0,sizeof(visit));
	bfsq.push({st,2e9}); // INF를 가지고 시작
	visit[st]=2e9;
	int ret=-1;
	while(!bfsq.empty()){
		auto here=bfsq.front(); // 꺼낸 후 pop -> & 사용불가
		bfsq.pop();
		if(here.fi==ed){
			ret=max(ret,here.se);
			continue;
		}
		for(auto& p:adj[here.fi])
			if(here.se>visit[p.fi]){
				visit[p.fi]=here.se;
				bfsq.push({p.fi, min(here.se, p.se)});	
			}
	}
	cout<<ret<<'\n';
	return 0;
}