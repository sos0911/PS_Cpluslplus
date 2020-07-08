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
ll N,L,I;
ll dp[32][32];
char ans[32]; //ans
void solve(ll n, ll l, ll i, int pos){
	// n : 앞으로 볼 자리수
	// 한 자리씩 정해 간다.
	if(n==0) // 모든 자리를 결정
		return;
	if(l==0){ // 자리는 남았으나 사용 가능한 1이 없음
		FOR(j,0,n,1)
			ans[pos+j]='0';
		return;
	}
	ll stn=dp[n-1][l];
	if(i<=stn){
		ans[pos]='0';
		solve(n-1,l,i,pos+1);
	}
	else{
		ans[pos]='1';
		solve(n-1,l-1,i-stn,pos+1);
	}
}
ll precal(ll n, ll l){
	ll& ret=dp[n][l];
	if(ret!=-1)
		return ret;
	if(n==0||l==0) // 볼 비트 수가 없거나 1 기준치 초과
		// 더 이상 1을 쓸 수 없으면 남은 선택지는 모두 0 = 1개
		return ret=1;
	// 각 자리당 0,1 두개 선택지
	ret=precal(n-1,l);
	ret+=precal(n-1,l-1);
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>N>>L>>I;
	// 먼저 전체 범위 내 수 개수를 구한다.
	// dp[n][l] : n개 자리수를 가진 이진수 중 1이 l개 이하
	memset(dp, -1, sizeof(dp));
	precal(N,L);
	solve(N,L,I,0);
	FOR(i,0,N,1)
		cout<<ans[i];
	cout<<'\n';
	return 0;
}