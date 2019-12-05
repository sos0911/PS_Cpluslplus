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
int n,r;
pii p[101], m[101];
// 가중치 +, 가중치 -
// (요구치, rating 변화치)
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>r;
	int pidx=0, midx=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(b>=0)
			p[pidx++]={a,b};
		else
			m[midx++]={a,b};
	}
	sort(p,p+pidx);
	sort(m,m+midx);
	// rating 최대로 올려봄
	for(int i=0;i<pidx;i++)
		if(p[i].fi<=r)
			r+=p[i].se;
		else{
			cout<<"NO"<<'\n';
				return 0;
		}
	// 내려봄
	for(int i=midx-1;i>=0;i--)
		if(m[i].fi<=r)
			r+=m[i].se;
		else{
			cout<<"NO"<<'\n';
				return 0;
		}
	cout<<"YES"<<'\n';
	return 0;
}