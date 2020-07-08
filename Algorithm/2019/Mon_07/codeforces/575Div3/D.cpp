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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	cin>>q;
	string st="RGB";
	FOR(i,0,q,1){
		int n,k,ans=1e9; string s;
		cin>>n>>k>>s;
		FOR(offset,0,3,1){ // offset
			// to pointer
			int res[n];
			int cur=0;
			FOR(j,0,n,1){
				res[j]=(s[j]!=st[(j+offset)%3]);
				cur+=res[j];
				if(j>=k)
					cur-=res[j-k];
				if(j>=k-1)
					ans=min(ans,cur);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}