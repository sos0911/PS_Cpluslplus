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
const int MAXD=16, INF=1e9;
int n,p,cnt=0; // 각 단계마다의 멀쩡한 발전소 수
int cost[MAXD][MAXD];
int dp[1<<MAXD];
// 0-15 저장 (index)
int solve(int visit){
	// 현 상태가 visit일때 앞으로 고치는 가짓수 중 최솟값 반환
	if(cnt>=p)
		return 0;
	int& ret=dp[visit];
	if(ret!=INF)
		return ret;
	cnt++;
	// 아래 for문에서 조건통과 시 하나가 추가되므로
		for(int i=0;i<n;i++){
			if(visit&(1<<i))
			for(int j=0;j<n;j++)
				if(!(visit&(1<<j)))
					ret=min(ret,solve(visit|(1<<j))+cost[i][j]);
		}
	cnt--;
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR(i,0,n,1)
		FOR(j,0,n,1)
			cin>>cost[i][j];
	string st;
	int stv=0; // st visit
	cin>>st>>p;
	// 1번쨰 발전기는 1<<0에 저장된다.
	FOR(i,0,st.size(),1)
		if(st[i]=='Y'){
			cnt++;
			stv|=1<<i;
		}
	fill(dp, dp+(1<<MAXD), INF);
	cout<<(solve(stv)==INF? -1:solve(stv))<<'\n';
	return 0;
}