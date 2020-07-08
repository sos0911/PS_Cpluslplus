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
const int MAXD=10001;
int n;
string st, ed;
int dp[MAXD][10]; // 0-9
int cache[MAXD][10]; // 각 조건에서 +이면 왼쪽이 이득, -이면 오른쪽이 이득
int solve(int here, int offset){
	// here번 나사가 offset만큼 원래 위치에서 돌아갔을 때
	// here 포함 아래 나사들이 최적 위치까지 돌아가는 데 걸리는
	// 최소 회수 반환
	int& ret=dp[here][offset];
	if(ret!=-1)
		return ret;
	if(here==n) // base case
		return 0;
	int curind=((st[here]-'0')+offset)%10;
	int goalind=ed[here]-'0';
	int l=1e9,r=1e9;
	int rep=abs(curind-goalind);
	if(curind>=goalind){
		// 다시보기 시발
		r=min(r,solve(here+1,offset)+rep); // 오른쪽 회전
		l=min(l,solve(here+1,(offset+10-rep)%10)+10-rep); // 왼쪽 회전
		cache[here][offset]=l<=r? 10-rep:-rep;
	}
	else{
		r=min(r,solve(here+1,offset)+10-rep); // 오른쪽 회전
		l=min(l,solve(here+1,(offset+rep)%10)+rep); // 왼쪽 회전
		cache[here][offset]=l<=r? rep:-(10-rep);
	}
	return ret=min(l,r);
}
void track(int here, int offset){
	if(here==n)
		return;
	int& ret=cache[here][offset];
	cout<<here+1<<" "<<cache[here][offset]<<'\n';
	if(ret>=0)
		track(here+1,(offset+ret)%10);
	else
		track(here+1,offset);
}
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>st>>ed;
	memset(dp, -1, sizeof(dp));
	cout<<solve(0,0)<<'\n'; // dp
	track(0,0);
	return 0;
}