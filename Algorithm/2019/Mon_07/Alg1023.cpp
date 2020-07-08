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
ll n,k;
ll dp[51][103][2]; // 비괄호 문자열 저장
// idx 이후로 볼 때 해결하는 '('개수가 nofp고 도중에 nofp가 <0이 된 여부
// 가 주어질 때 비괄호 문자열 수 저장
// 두번째 idx는 +n 주의(음수도 memoi)
ll solve(int idx, int nofp, bool under){
	if(idx==n)
		return (nofp||under);
	// nofp가 0이 아니면 true
	ll& ret=dp[idx][nofp+n][under];
	// under=true면 th index 1
	if(ret!=-1)
		return ret;
	ret=0;
	// 두 개를 각각 붙여본다.
	ret+=solve(idx+1,nofp+1,under);
	ret+=solve(idx+1,nofp-1,under||nofp<=0);
	return ret;
}
void track(int idx, int nofp, bool under, ll order){
	if(idx==n-1){
		if(order==1)
			cout<<'(';
		else
			cout<<')';
		return;	
	}
	ll& ret=dp[idx+1][nofp+n+1][under];
	if(order<=ret){
		cout<<'(';
		track(idx+1,nofp+1,under,order);
	}
	else{
		cout<<')';
		track(idx+1,nofp-1,under||nofp<=0,order-ret);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	solve(0,0,false);
	if(k+1>dp[0][n][0])
		cout<<-1;
	else
	track(0,0,false,k+1);
	cout<<'\n';
	return 0;
}