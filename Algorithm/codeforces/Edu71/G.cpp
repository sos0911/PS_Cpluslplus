// 대회용 템플릿
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
// disjoint-set
// tc : O(nlogn+mlogm+n+m)
const int maxd=2e5;
int par[maxd+1], ts[maxd+1];
int n,m;
pii q[maxd+1]; // (쿼리, idx)
struct Info{
	int a,b,c;
};
Info in[maxd+1];
ll res=0; // 유지하는 그때마다의 쿼리 답
ll ans[maxd+1];
// 노드가 루트일 경우 해당 트리의 size 저장
bool comp(Info& i1, Info& i2){
	return i1.c<i2.c;
}
int find(int node){
	if(par[node]==node)
	return node;
return par[node]=find(par[node]);
}
void merge(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(ts[a]>ts[b])
		swap(a,b);
	res-=1LL*ts[a]*(ts[a]-1)/2;
	res-=1LL*ts[b]*(ts[b]-1)/2;
	ts[b]+=ts[a];
	par[a]=b;
	res+=1LL*ts[b]*(ts[b]-1)/2;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ // dsu 초기화
		par[i]=i;
		ts[i]=1;
	}
	for(int i=0;i<n-1;i++)
		cin>>in[i].a>>in[i].b>>in[i].c;
	for(int i=0;i<m;i++){
		cin>>q[i].fi;
		q[i].se=i;
	}
	sort(in,in+n-1,comp);
	sort(q,q+m);
	int pos=0;
	for(int i=0;i<m;i++){
		while(pos<n-1&&in[pos].c<=q[i].fi){
			merge(in[pos].a,in[pos].b);
			pos++;
		}
		ans[q[i].se]=res;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<" ";
	cout<<'\n';
	return 0;
}