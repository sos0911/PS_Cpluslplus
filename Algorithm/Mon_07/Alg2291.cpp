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
int N,M,K;
ll dp[11][221][221];
ll solve(int n, int m, int prev){
	// 남은 길이가 n이고, 남은 합이 m이고 그 전 수가 prev이었을때
	// 가짓수 반환
	ll& ret=dp[n][m][prev];
	if(ret!=-1)
		return ret;
	if(n==1) // m>=prev
		return ret=1;
	ret=0;
	for(int i=prev;i*n<=m;i++) // n=0일 때까지 끌고 가는 조건
		ret+=solve(n-1,m-i,i); // overflow
	return ret;
}
void track(int n, int m, int prev, int order){
	if(n==1){
		cout<<m<<'\n';
		return;
	}
	ll rep=0, i=prev;
	while(true){
		if(rep+solve(n-1,m-i,i)>=order){
			cout<<i<<" ";
			track(n-1,m-i,i,order-rep);
			break;
		}
		rep+=solve(n-1,m-i,i);
		i++;
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>N>>M>>K;
	memset(dp,-1,sizeof(dp));
	solve(N,M,1);
	track(N,M,1,K);
	return 0;
}