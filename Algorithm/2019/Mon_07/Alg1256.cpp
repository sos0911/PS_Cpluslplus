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
int n,m,k;
int dp[201][101][101];
const int mod=1e9;
int solve(int idx, int nofa, int nofz){
	// idx번째 문자 포함 그 뒤에서 만들어지는 가짓수 반환
	int& ret=dp[idx][nofa][nofz];
	if(ret!=-1)
		return ret;
	if(idx==n+m+1)
		return 0;
	if(nofa==0||nofz==0)
		return ret=1;
	// a or b를 붙여본다.
	ret=0;
	ret+=solve(idx+1,nofa-1,nofz);
	ret+=solve(idx+1,nofa,nofz-1);
	ret=ret>mod? mod+1:ret;
	// mod보다 크면 mod+1로 고정
	return ret;
}
void track(int idx, int nofa, int nofz, int order){
	//cout<<"track : "<<idx<<" "<<nofa<<" "<<nofz<<" "<<order<<'\n';
	if(idx==n+m){
		cout<<(nofa>0? 'a':'z');
		return;
	}
	int& stn=dp[idx+1][nofa-1][nofz];
	//cout<<"stn : "<<stn<<'\n';
	if(order<=stn){
		cout<<'a';
		track(idx+1,nofa-1,nofz,order);
	}
	else{
		cout<<'z';
		track(idx+1,nofa,nofz-1,order-stn);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	solve(1,n,m);
	if(k>dp[1][n][m])
		cout<<-1;
	else
	track(1,n,m,k); // tracking
	cout<<'\n';
	return 0;
}
// 40 40 1 
