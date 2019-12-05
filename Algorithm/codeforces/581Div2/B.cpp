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
int n,l,r;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>l>>r;
	int minv=1, maxv=1;
	int rep=1;
	for(int i=1;i<n;i++)
		if(i<=n-l)
			minv+=1;
		else{
			rep*=2;
			minv+=rep;
		}
	int rep2=r-1, rep3=1;
	for(int i=1;i<n;i++)
		if(rep2){
			rep3*=2;
			maxv+=rep3;
			rep2--;
		}
		else
			maxv+=rep3;
	cout<<minv<<" "<<maxv<<'\n';
	return 0;
}