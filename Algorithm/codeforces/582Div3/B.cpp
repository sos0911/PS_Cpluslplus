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
const int maxd=1e6;
int tree[maxd*4], in[150001];
int n,t,start;
void update(int i, int add){
	i+=start;
	tree[i]+=add;
	while(i>1){
		i/=2;
		tree[i]=tree[i*2]+tree[i*2+1];
	}
}
int query(int left, int right, int node, int nleft, int nright){
	if(right<nleft||left>nright)
		return 0;
	if(left<=nleft&&nright<=right)
		return tree[node];
	int mid=(nleft+nright)/2;
	return query(left,right,node*2,nleft,mid)+query(left,right,node*2+1,mid+1,nright);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int maxv=-1;
		for(int j=0;j<n;j++){
			cin>>in[j];
			maxv=max(maxv,in[j]);
		}
		start=1;
		while(start<maxv+1)
			start*=2;
		fill(tree,tree+start*2,0);
		int ans=0;
		for(int j=n-1;j>=0;j--){
			if(query(0,in[j]-1,1,0,start-1))
				ans++;
			update(in[j],1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}