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
string s,t;
int dp[202][202];
const int maxd=1e9;
int solve(int tpos, int spos){
	// spos가 마지막으로 사용한 idx
	// tpos가 이번에 찾아야 하는 문자
	// 남은 구간에서 찾는 최대길이 반환
	if(tpos==t.size())
		return s.size()-spos-1;
	if(spos>=(int)s.size()-1) // 완성 못함
		return -maxd;
	int& ret=dp[tpos][spos+1];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=spos+1;i<s.size();i++)
		if(t[tpos]==s[i]&&solve(tpos+1,i)!=-maxd)
			ret=max(ret,max(solve(tpos+1,i),i-spos-1));
	return ret;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,-1)<<'\n';
	return 0;
}