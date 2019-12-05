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
int n;
string ans(80,'0');
bool possi(int idx, int i){
	// 해당 위치에 i가 가능한가?
	ans[idx]=(char)(i+'0');
	if(idx==0)
		return true;
	for(int j=1;idx-2*j+1>=0;j++)
		if(ans.substr(idx-2*j+1,j)==ans.substr(idx-j+1,j))
			return false;
	return true;
}
bool solve(int idx){
	// string idx
	if(idx==n){
		cout<<ans.substr(0,n)<<'\n';
		return true;
	}
	FOR(i,1,4,1)
	if(possi(idx,i))
		if(solve(idx+1))
			return true;
	return false;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	solve(0);
	return 0;
}