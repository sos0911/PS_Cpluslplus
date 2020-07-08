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
int n,t;
int dp[101][10001];
pii in[101]; // (공부시간, 배점)
int knapsack(int idx, int left){
	// idx번째를 보고 있고 남은 용량이 left라면
	// 앞으로의 선택에서 얻는 최대 점수 반환
	// tc : O(NT)
	if(idx==n)
		return 0;
	int& ret=dp[idx][left];
	if(ret!=-1)
		return ret;
	// 선택하는 것과 안 하는 것
	ret=knapsack(idx+1,left);
	if(left>=in[idx].fi)
		ret=max(ret,knapsack(idx+1,left-in[idx].fi)+in[idx].se);
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>t;
	FOR(i,0,n,1)
		cin>>in[i].fi>>in[i].se;
	FOR(i,0,n,1)
		fill(dp[i],dp[i]+t+1,-1);
	cout<<knapsack(0,t)<<'\n';
	return 0;
}