#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	pii in[n]; // (L,H)
	FOR(i,0,n,1)
		cin>>in[i].fi>>in[i].se;
	sort(in,in+n);
	int ret=0; // ans
	// 왼쪽에서 한번
	pii lcur=in[0];
	FOR(i,1,n,1)
		if(lcur.se<in[i].se){
			ret+=abs(in[i].fi-lcur.fi)*lcur.se;
			lcur=in[i];	
		}
	// 오른쪽에서 한번
	pii rcur=in[n-1];
	RFOR(i,n-2,0,-1)
		if(rcur.se<in[i].se){
			ret+=abs(in[i].fi-rcur.fi)*rcur.se;
			rcur=in[i];	
		}
	// 마지막 수합
	ret+=(abs(lcur.fi-rcur.fi)+1)*min(lcur.se,rcur.se);
	cout<<ret<<'\n';
	return 0;
}