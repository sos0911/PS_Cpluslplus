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
	int cpow[8];
	int rep=1;
	for(int i=0;i<8;i++){
		cpow[i]=rep;
		rep*=10;
	}
	int n;
	cin>>n;
	int acc[26];
	memset(acc,0,sizeof(acc));
	FOR(i,0,n,1){
		string in;
		cin>>in;
		FOR(j,0,in.size(),1)
			acc[in[j]-'A']-=cpow[in.size()-j-1];
	}
	sort(acc,acc+26);
	int ans=0;
	FOR(i,0,10,1)
		ans+=(9-i)*-acc[i];
	cout<<ans<<'\n';
	return 0;
}