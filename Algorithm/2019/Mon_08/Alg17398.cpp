// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,m,q;
const int maxd=1e5+1;
// 역순으로 문제풀기 (union-find)
pii in[maxd]; bool check[maxd]={}, visit[maxd]={};
vector<vector<int>> adj;
int p[maxd], crank[maxd], eli[maxd], tsize[maxd];
// tsize : 노드가 루트일 시 트리 사이즈 저장
// 0부터 시작
int find(int node){
	if(p[node]==node)
		return node;
	return p[node]=find(p[node]);
}
void merge(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(crank[a]>crank[b])
		swap(a,b);
	p[a]=b;
	if(crank[a]==crank[b])
		crank[b]++;
	tsize[b]+=tsize[a];
}
void dfs(int node){
	visit[node]=true;
	for(int next:adj[node])
		if(!visit[next]){
			merge(node,next);
			dfs(next);
		}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>q;
	adj.assign(n+1,vector<int>());
	for(int i=1;i<=m;i++)
		cin>>in[i].fi>>in[i].se;
	for(int i=0;i<q;i++){
		int temp;
		cin>>temp;
		check[temp]=true;
		eli[i]=temp;
	}
	for(int i=1;i<=m;i++)
		if(!check[i]){
			int a=in[i].fi, b=in[i].se;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	// dfs로 집합완성
	for(int i=1;i<=n;i++){
		p[i]=i;
		crank[i]=1;
		tsize[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(!visit[i])
			dfs(i);
	ll ans=0;
	for(int i=q-1;i>=0;i--){
		int a=in[eli[i]].fi;
		int b=in[eli[i]].se;
		if(find(a)!=find(b)){
			ans+=1LL*tsize[find(a)]*tsize[find(b)];
			merge(a,b);
		}
	}
	cout<<ans<<'\n';
	return 0;
}