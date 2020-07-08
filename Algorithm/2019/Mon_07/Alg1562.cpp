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
int dp[101][10][1<<10];
const int mod=1e9;
int solve(int cnt, int prev, int visit){
	// 지금까지 cnt개를 완성시켰고 전 게 prev
	// 완성하는 계단 수 수 반환
	if(cnt==n)
		if(visit==(1<<10)-1)
			return 1;
		else
			return 0;
	int& ret=dp[cnt][prev][visit];
	if(ret!=-1)
		return ret;
	// 선택지 2개
	ret=0;
	if(prev-1>=0){
		if(visit&(1<<(prev-1)))
			ret+=solve(cnt+1,prev-1,visit);
		else
			ret+=solve(cnt+1,prev-1,visit|(1<<(prev-1)));
	}
	if(prev+1<=9){
		if(visit&(1<<(prev+1)))
			ret+=solve(cnt+1,prev+1,visit);
		else
			ret+=solve(cnt+1,prev+1,visit|(1<<(prev+1)));
	}
	return ret%=mod;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int ans=0;
	FOR(i,1,10,1){
		ans+=solve(1,i,1<<i);
		ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}